#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def callback(message):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", message.data)
    #rospy.loginfo(f"{rospy.get_caller_id()} I heard {message.data}")

def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('chatter', String, callback)
    rospy.spin()


if __name__ == '__main__':
    listener()
