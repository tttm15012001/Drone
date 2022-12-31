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

bool isReceived = false;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

void chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  if(msg->data == "land" && check_waypoint_reached() == 1) {
    land();
  } else {
    // char* tempData = strdup(msg->data.c_str());
    // int devide_index = msg->data.find("***");
    // char drone3_msg_temp[100];
    // strncpy(drone3_msg_temp, msg->data.c_str() + 4 + devide_index, msg->data.length() - 4 - devide_index);
    // drone3_msg_temp[msg->data.length() - 4 - devide_index] = '\0';
    // string drone3_msg = string(drone3_msg_temp);
    string drone3_msg = msg->data;
    if(drone3_msg.substr(0, 6) == "drone3") {
      cout << "++++++++++++++++++++++++++++++++++" << endl;
      int drone3_msg_index = drone3_msg.find(":");
      char drone3_content[50];
      strncpy(drone3_content, drone3_msg.c_str() + 2 + drone3_msg_index, drone3_msg.length() - 3 - drone3_msg_index);
      drone3_content[drone3_msg.length() - 3 - drone3_msg_index] = '\0';
      cout << drone3_content << endl;
      float *arr_temp = new float[4];
      float arr[4] = {0};
      splitWayPointFromMsg(arr_temp, drone3_content);
      for(int i = 0; i < 4; i++) {
        arr[i] = *(arr_temp + i);
        cout << arr[i] << ' ';
      }
      cout << endl;
      set_destination(arr[0], arr[1], 2, arr[3]);
      isReceived = true;
    }
  }
  // ROS_INFO("I heard: [%s] from chatter2", msg->data.c_str());
}

int main(int argc, char** argv)
{
  //initialize ros 
  ros::init(argc, argv, "drone3");
  ros::NodeHandle drone3("~");

  ros::Publisher chatter_pub3 = drone3.advertise<std_msgs::String>("chatter3", 1000);
  // ros::Subscriber sub3 = drone3.subscribe("/drone2/square2/chatter2", 1000, chatterCallback2);
  // ros::Subscriber sub3 = drone3.subscribe("/drone1/controller", 1000, chatterCallback2);
  ros::Subscriber sub3 = drone3.subscribe("/drone1/square1/controller", 1000, chatterCallback2);
  
  //initialize control publisher/subscribers
  init_publisher_subscriber(drone3);

    // wait for FCU connection
  wait4connect();

  //wait for used to switch to mode GUIDED
  set_mode("GUIDED");
  // wait4start();

  //create local reference frame 
  initialize_local_frame();

  //request takeoff
  takeoff(2);

  //specify control loop rate. We recommend a low frequency to not over load the FCU with messages. Too many messages will cause the drone to be sluggish
  ros::Rate rate(2.0);
  int counter = 0;
  while(ros::ok())
  {
    ros::spinOnce();
    rate.sleep();
    if(check_waypoint_reached() == 1) {
      if(isReceived == true) {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "drone 3 reached";

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        chatter_pub3.publish(msg);
      }
    }
  }
  return 0;
}