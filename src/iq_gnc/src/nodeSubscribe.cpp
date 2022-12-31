#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gnc_functions.hpp>
#include <iostream>
#include <stdio.h>
#include "std_msgs/String.h"
#include <string>
#include <cstring>
#include <sstream> 

using namespace std;

bool isReceive = false;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

void chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
  if(msg->data == "land" && check_waypoint_reached() == 1) {
    land();
  } else {
    // char* tempData = strdup(msg->data.c_str());
    // string drone2_msg = strtok(tempData, "***");
    string drone2_msg = msg->data;
    if(drone2_msg.substr(0, 6) == "drone2") {
      cout << "++++++++++++++++++++++++++++++++++" << endl;
      int drone2_msg_index = drone2_msg.find(":");
      char drone2_content[100]; 
      strncpy(drone2_content, drone2_msg.c_str() + 2 + drone2_msg_index, drone2_msg.length() - 3 - drone2_msg_index);
      drone2_content[drone2_msg.length() - 3 - drone2_msg_index] = '\0';
      // drone2_content[10] = '\0';
      cout << drone2_content << endl;
      float *arr_temp = new float[4];
      float arr[4] = {0};
      splitWayPointFromMsg(arr_temp, drone2_content);
      for(int i = 0; i < 4; i++) {
        arr[i] = *(arr_temp + i);
        cout << arr[i] << ' ';
      }
      cout << endl;
      set_destination(arr[0], arr[1], arr[2], arr[3]);
      isReceive = true;
    }
  }
  // ROS_INFO("1 -- I heard: [%s] from controller", drone2_content);
}
 
int main(int argc, char** argv)
{
  //initialize ros 
  ros::init(argc, argv, "drone2");
  ros::NodeHandle drone2("~");

  ros::Publisher chatter_pub2 = drone2.advertise<std_msgs::String>("chatter2", 1000);

  // for test
  // ros::Subscriber sub2 = drone2.subscribe("/drone1/controller", 1000, chatterCallback1);
  // end test

  ros::Subscriber sub2 = drone2.subscribe("/drone1/square1/controller", 1000, chatterCallback1);
  
  //initialize control publisher/subscribers
  init_publisher_subscriber(drone2);

  // wait for FCU connection
  wait4connect();

  //wait for used to switch to mode GUIDED
  set_mode("GUIDED");
  // wait4start();

  //create local reference frame 
  initialize_local_frame();

  //request takeoff
  takeoff(3);

  //specify control loop rate. We recommend a low frequency to not over load the FCU with messages. Too many messages will cause the drone to be sluggish
  ros::Rate rate(2.0);
  int counter = 0;
  while(ros::ok())
  {
    // std_msgs::String msg;

    // std::stringstream ss;
    // ss << "hello world 1";
    // msg.data = ss.str();

    // ROS_INFO("%s", msg.data.c_str());

    // chatter_pub2.publish(msg);

    ros::spinOnce();
    rate.sleep();
    if(check_waypoint_reached() == 1) {
      if(isReceive == true) {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "drone 2 reached";

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        chatter_pub2.publish(msg);
      }
    }
  }
  return 0;
}