#! /usr/bin/env python
# Import ROS.
import rospy
from iq_gnc.py_gnc_functions import *
from iq_gnc.PrintColours import *
from iq_gnc.ManageDrones import manageDrones, LANDING, LANDED, TAKING_OFF, TAKEOFF
from std_msgs.msg import String

drone = gnc_api()
manageDrone = manageDrones(1)
canReceive = True

def callback(data):
    global canReceive
    if canReceive == True or data.data.find('drone4: ') != -1:
        rospy.loginfo(rospy.get_caller_id() + " I heard %s", data.data)
        if(data.data == 'land'):
            drone.land()
        else:
            analizeData = data.data.split(': ')
            if analizeData[0] == 'takeoff':
                if 'drone4True' in analizeData[1]:
                    drone.takeoff(1)
                    manageDrone.updateState('drone3 ', TAKING_OFF)
            elif manageDrone.state == TAKEOFF and analizeData[0] == 'drone4':
                coordinates_arr = analizeData[1].split()
                drone.set_destination(x=float(coordinates_arr[0]), y=float("-6"), z=float(coordinates_arr[2]), psi=0)
        canReceive = False

def main():
    # Initializing ROS node.
    rospy.init_node("drone4", anonymous=True)
    
    chatter_pub4 = rospy.Publisher(name='drone4_listen', data_class=String, queue_size=100)
    rospy.Subscriber(name="/drone1/master", data_class=String, queue_size=10, callback=callback)

    drone.wait4connect()
    drone.set_mode("GUIDED")
    drone.initialize_local_frame()
    # Specify control loop rate. We recommend a low frequency to not over load the FCU with messages. Too many messages will cause the drone to be sluggish.
    rate = rospy.Rate(2)

    counter = 0
    while not rospy.is_shutdown():
        rate.sleep()
        if manageDrone.state == LANDED:
            counter = 0
        elif counter > 8 and drone.check_waypoint_reached():
            data = 'reached:4'
            rospy.loginfo(data)
            chatter_pub4.publish(data)
            global canReceive
            canReceive = True
        elif counter == 8:
            manageDrone.updateState('drone4 ', TAKEOFF)
            data = 'takeoff:4'
            rospy.loginfo(data)
            chatter_pub4.publish(data)
            counter += 1
        elif manageDrone.state == TAKING_OFF:
            counter += 1
        else:
            print('waiting for another signal')
        

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        exit()
