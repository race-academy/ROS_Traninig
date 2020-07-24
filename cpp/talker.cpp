#include "ros/ros.h"            // ROS header file for C++
#include "std_msgs/String.h"    // String one of the standard msgs data type in ROS
#include "std_msgs/Int16.h"     // example for ros msg data type vs c data type
#include <sstream>

// C++ main method
int main(int argc, char **argv){ 

// node name(talker) for ROS to do name remapping, need to be unique
ros::init(argc, argv, "talker");

// process handler for this talker node
ros::NodeHandle n;

// let the ROS master to know we are going to publish a message of std_msgs/String on the topic of chatter 
// n.advertis return a Publisher object(chatter_pub) for us to put the msg to publish on the topic
// 100 is the message queue size. eg your msg publisted too fast than we can send. 100 msg will be keep in buffer to queue up 
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 100);

// Rate is an object for specify the frequency you would like to loop at. 1 = 1Hz so is 1sec (t = 1/f, t = 1 /1Hz = 1 sec)
ros::Rate loop_rate(1);

// c++ int count as zero
int count = 0;

// ros::ok() will return false if:
//a SIGINT is received (Ctrl-C), // SIGINT is signle handler which provides Ctrl-C handling
//we have been kicked off the network by another node with the same name
//ros::shutdown() has been called by another part of the application.
//all ros::NodeHandles have been destroyed
while(ros::ok()){

    // We broadcast a message on ROS using a message-adapted class, generally generated from a msg file. More complicated datatypes are possible, but for now we're going to use the standard String message, which has one member: "data".
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello jaden " << count;
    msg.data = ss.str();

    // ROS_INFO and friends are our replacement for printf/cout. See the rosconsole documentation for more information.
    ROS_INFO("%s", msg.data.c_str());

    // Now we actually broadcast the message to anyone who is connected.
    chatter_pub.publish(msg);

    // Calling ros::spinOnce() here is not necessary for this simple program, because we are not receiving any callbacks. However, if you were to add a subscription into this application, and did not have ros::spinOnce() here, your callbacks would never get called. So, add it for good measure.
    // use for both publisher and subscriber in a node
    ros::spinOnce();

    //Now we use the ros::Rate object to sleep for the time remaining to let us hit our 1Hz publish rate.
    loop_rate.sleep();

    // c++ increase count 
    ++count;
}   

return 0;

}