#include <gnc_functions.hpp>
#include <iostream>
#include "std_msgs/String.h"
#include <cstring>
#include <fstream>
#include <string>

#include <sstream>

using namespace std;
//include API 

bool drone2Reach = false;
bool drone3Reach = false;	

string convertMessage(gnc_api_waypoint currentWayPoint) {
	std::string result;
	result += std::to_string(currentWayPoint.x) + ' ' + std::to_string(currentWayPoint.y) + ' ' + std::to_string(currentWayPoint.z) + ' ' + std::to_string(currentWayPoint.psi);
	return result;
}

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
	drone2Reach = (msg->data == "drone 2 reached") ? true : false;
	drone3Reach = (msg->data == "drone 3 reached") ? true : false;
	if(drone2Reach && drone3Reach) {
		land();
	}
}

int main(int argc, char** argv)
{
	//initialize ros 
	ros::init(argc, argv, "drone1");
	ros::NodeHandle drone1("~");

	ros::Publisher chatter_pub = drone1.advertise<std_msgs::String>("controller", 1000);
	ros::Subscriber sub2 = drone1.subscribe("/drone2/square2/chatter2", 1000, chatterCallback);
	// ros::Subscriber sub3 = drone1.subscribe("/drone3/square3/chatter3", 1000, chatterCallback);
	
	//initialize control publisher/subscribers
	init_publisher_subscriber(drone1);

  	// wait for FCU connection
	wait4connect();

	//wait for used to switch to mode GUIDED
	set_mode("GUIDED");
	// wait4start();

	//create local reference frame 
	initialize_local_frame();

	//request takeoff
	takeoff(4);

	//specify some waypoints 
	// std::vector<gnc_api_waypoint> waypointList;
	// gnc_api_waypoint nextWayPoint;
	// nextWayPoint.x = 0;
	// nextWayPoint.y = 0;
	// nextWayPoint.z = 4;
	// nextWayPoint.psi = 0;
	// waypointList.push_back(nextWayPoint);
	// nextWayPoint.x = 5;
	// nextWayPoint.y = 0;
	// nextWayPoint.z = 4;
	// nextWayPoint.psi = -90;
	// waypointList.push_back(nextWayPoint);
	// nextWayPoint.x = 5;
	// nextWayPoint.y = 5;
	// nextWayPoint.z = 4;
	// nextWayPoint.psi = 0;
	// waypointList.push_back(nextWayPoint);
	// nextWayPoint.x = 0;
	// nextWayPoint.y = 5;
	// nextWayPoint.z = 4;
	// nextWayPoint.psi = 90;
	// waypointList.push_back(nextWayPoint);
	// nextWayPoint.x = 0;
	// nextWayPoint.y = 0;
	// nextWayPoint.z = 4;
	// nextWayPoint.psi = 180;
	// waypointList.push_back(nextWayPoint);
	// nextWayPoint.x = 0;
	// nextWayPoint.y = 0;
	// nextWayPoint.z = 0;
	// nextWayPoint.psi = 0;
	// waypointList.push_back(nextWayPoint);

	//specify control loop rate. We recommend a low frequency to not over load the FCU with messages. Too many messages will cause the drone to be sluggish
	ros::Rate rate(2.0);
	int numRead = 0;
	while(ros::ok())
	{
		std_msgs::String msg;

		string data;

		ros::spinOnce();
		rate.sleep();
		if(check_waypoint_reached() == 1) {
			if(numRead > 0) {
				cout << "ccc" << endl;
			} else {
				cout << "cc" << endl;
				ifstream inputFile("filename.txt");
				cout << "c" << endl;
				while(getline(inputFile, data)) {
					std::stringstream ss;
					ss << data;
					cout << data << endl;
					if(data.substr(0, 6) == "drone1") {
						numRead++;
						int drone2_msg_index = data.find(":");
						char drone2_content[100]; 
						strncpy(drone2_content, data.c_str() + 2 + drone2_msg_index, data.length() - 2 - drone2_msg_index);
						drone2_content[data.length() - 2 - drone2_msg_index] = '\0';
						// drone2_content[10] = '\0';
						float *arr_temp = new float[4];
						float arr[4] = {0};
						splitWayPointFromMsg(arr_temp, drone2_content);
						for(int i = 0; i < 4; i++) {
							arr[i] = *(arr_temp + i);
						}
						set_destination(arr[0], arr[1], arr[2], arr[3]);
					}

					msg.data = ss.str();

					ROS_INFO("%s", msg.data.c_str());
					chatter_pub.publish(msg);
				}
			}
		}
	}
	return 0;
}