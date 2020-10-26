#include "ros/ros.h"            // ROS header file for C++
#include "std_msgs/String.h"   // String one of the standard msgs data type in ROS

// This is the callback function that will get called when a new message has arrived on the chatter topic. 
void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

// C++ main method
int main(int argc, char **argv){

// node name(listener) for ROS to do name remapping, need to be unique
ros::init(argc, argv, "listener");

// process handler for this listener nod
ros::NodeHandle n;
// Subscribe to the chatter topic with the master. ROS will call the chatterCallback() function whenever a new message arrives.
// 100 is the message quene size
ros::Subscriber sub = n.subscribe("chatter", 100, chatterCallback);

// ros::spin() enters a loop, calling message callbacks as fast as possible.
ros::spin();
return 0;
}
