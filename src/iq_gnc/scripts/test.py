#! /usr/bin/env python
# Import ROS.
import rospy
# Import the API.
from iq_gnc.py_gnc_functions import *
# To print colours (optional).
from iq_gnc.PrintColours import *
from geometry_msgs.msg import Pose, PoseStamped, Point, Quaternion
from std_msgs.msg import String
from iq_gnc.ManageDrones import manageDrones, coordinates, LANDING, LANDED, TAKING_OFF, TAKEOFF
        
def main():
    # Initializing ROS node.
    rospy.init_node("drone1", anonymous=True)
    chatter_pub = rospy.Publisher(name='master', data_class=String, queue_size=100)
    
    drone = gnc_api()

    # Wait for FCU connection.
    drone.wait4connect()
    # Wait for the mode to be switched.
    # drone.wait4start()
    drone.set_mode("GUIDED")

    # Create local reference frame.
    drone.initialize_local_frame()
    # Request takeoff with an altitude of 3m.
    
    drone.takeoff(4)
    
    print(dir(drone))
    
    # Specify control loop rate. We recommend a low frequency to not over load the FCU with messages. Too many messages will cause the drone to be sluggish.
    rate = rospy.Rate(2)

    counter = 0
    stay = 0
    countDownSleep = 40
    while not rospy.is_shutdown():
        rate.sleep()
            
            
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        exit()
