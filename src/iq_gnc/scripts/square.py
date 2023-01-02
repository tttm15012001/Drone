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

# Create an object for the API.
drone = gnc_api()

manageDrone = manageDrones(3)
        
def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    splitData = data.data.split(':')
    if splitData[0] == 'takeoff':
        manageDrone.updateReady(int(splitData[1][0:1]) - 2)  
    elif splitData[0] == 'reached':    
        manageDrone.updateSignal(int(splitData[1][0:1]) - 2)    
    
def handleDataFromServer(data):
    if manageDrone.state != LANDING:
        numDroneNeedToTakeOffArr = data.data.split()
        numDroneNeedToTakeOff = len(numDroneNeedToTakeOffArr)
        if manageDrone.state == LANDED:
            drone.takeoff(4)
            manageDrone.updateState('drone1 ', TAKING_OFF)
            manageDrone.needPublish = True
        elif manageDrone.checkEnough(numDroneNeedToTakeOff - 1) == False:
            manageDrone.needPublish = True
        manageDrone.requestXDroneTakeOff(numDroneNeedToTakeOff - 1)
        if(len(manageDrone.coordinatesAll) < 20):
            coordinates_str = data.data
            coordinates_arr = coordinates_str.split()   
            queue = []
            for pair in numDroneNeedToTakeOffArr:
                data = pair.split(',')
                newCoordinates = coordinates(int(data[0]) / 100, int("0"), int(data[1]) / 100)
                queue.insert(len(queue), newCoordinates)
            manageDrone.coordinatesAll.insert(0, queue)
        
def switch(topic, condition, countDownSleep, stay):
    if condition == 'landing':
        print('------ 0 Landing 0 ------')
        print('------ 1 You can\'t public your image 1 ------')
        if drone.check_waypoint_reached():
            manageDrone.updateState('drone1 ', LANDED)
    elif condition == 'takingoff':
        if manageDrone.needPublish:
            dataSend = 'takeoff: '
            for idx in range(len(manageDrone.requestTakeOff)):
                dataSend += 'drone' + str(idx + 2) + str(manageDrone.requestTakeOff[idx]) + ' '
            manageDrone.createData(dataSend)
            rospy.loginfo(manageDrone.dataSend)
            topic.publish(manageDrone.dataSend)
            manageDrone.needPublish = False
    elif condition == 'takeoff':
        if manageDrone.needPublish:
            dataSend = 'takeoff: '
            for idx in range(len(manageDrone.requestTakeOff)):
                action = 'land' if manageDrone.requestTakeOff[idx] == False else 'true' 
                dataSend += 'drone' + str(idx + 2) + str(action) + ' '
            manageDrone.createData(dataSend)
            rospy.loginfo(manageDrone.dataSend)
            topic.publish(manageDrone.dataSend)
            manageDrone.needPublish = False
        elif drone.check_waypoint_reached() and manageDrone.isReachAll():
            if countDownSleep > 0:
                if len(manageDrone.coordinatesAll) > 0:
                    manageDrone.unReachAll()
                    countDownSleep = 40
                    indexDestination = len(manageDrone.coordinatesAll) - 1
                    print('length: ' + str(indexDestination))
                    coor = manageDrone.coordinatesAll[indexDestination]
                    drone.set_destination(x=coor[0].coor_x, y=0, z=coor[0].coor_z, psi=coor[0].coor_psi)
                    for idx in range(1, len(coor)):
                        data = 'drone' + str(idx + 1) + ': ' + str(coor[idx].coor_x) + ' 0 ' + str(coor[idx].coor_z) + ' ' + str(coor[idx].coor_psi)
                        manageDrone.createData(data)
                        rospy.loginfo(manageDrone.dataSend)
                        topic.publish(manageDrone.dataSend)
                    manageDrone.coordinatesAll.pop(0)
                elif len(manageDrone.coordinatesAll) == 0:
                    countDownSleep -= 1
                print(str(countDownSleep))
            else:
                data = "land"
                rospy.loginfo(data)
                topic.publish(data)
                drone.land()
                manageDrone.updateState('drone1 ', LANDING)
                # rospy.loginfo(CGREEN2 + "All waypoints reached landing now." + CEND)
        elif stay % 4 == 0:
            # rospy.loginfo(manageDrone.dataSend)
            # topic.publish(manageDrone.dataSend)
            a = 1
        stay = (stay + 1) % 16
    elif condition == 'landed':
        print('---Landed---')
    return (countDownSleep, stay)
        
def main():
    # Initializing ROS node.
    rospy.init_node("drone1", anonymous=True)
    chatter_pub = rospy.Publisher(name='master', data_class=String, queue_size=100)
    
    # Subscribe for all sub drones
    rospy.Subscriber(name="/drone2/drone2_listen", data_class=String, queue_size=10, callback=callback)
    rospy.Subscriber(name="/drone3/drone3_listen", data_class=String, queue_size=10, callback=callback)
    rospy.Subscriber(name="/drone4/drone4_listen", data_class=String, queue_size=10, callback=callback)
    rospy.Subscriber(name="/server", data_class=String, queue_size=10, callback=handleDataFromServer)

    # Wait for FCU connection.
    drone.wait4connect()
    # Wait for the mode to be switched.
    # drone.wait4start()
    drone.set_mode("GUIDED")

    # Create local reference frame.
    drone.initialize_local_frame()
    # Request takeoff with an altitude of 3m.
    
    # Specify control loop rate. We recommend a low frequency to not over load the FCU with messages. Too many messages will cause the drone to be sluggish.
    rate = rospy.Rate(2)

    counter = 0
    stay = 0
    countDownSleep = 40
    while not rospy.is_shutdown():
        rate.sleep()
        print(manageDrone.state)
        if manageDrone.state == LANDED:
            counter = 0
        elif counter > 8:
            (countDownSleep, stay) = switch(chatter_pub, manageDrone.state, countDownSleep, stay)
            print(str(countDownSleep) + ' --- ' + str(stay))
        elif counter == 8:
            manageDrone.updateState('drone1 ', TAKEOFF)
            counter += 1
        elif manageDrone.state == TAKING_OFF:
            switch(chatter_pub, manageDrone.state, countDownSleep, stay)
            counter += 1
        else:
            print('waiting for signal')
            
            
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        exit()
