#include <sstream>
#include <iostream>

#include <ros/ros.h>
#include <std_msgs/String.h>

#include <mavconn/serial.h>

void cb (const mavlink::mavlink_message_t* message, const mavconn::Framing framing)
{}

int main (int argc, char** argv)
{
    ros::init (argc, argv, "serial");
    
    ros::NodeHandle nh;
    
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String> ("chatter", 1000);
    
    ros::Rate loop_rate (10);
    
    std::cerr << "Attempting to create driver\n";
       
    mavconn::MAVConnSerial driver;
    driver.message_received_cb = &cb;
    
    std::cerr << "Created driver\n";
    
    while (!driver.is_open());
    
    std_msgs::String msg;
    msg.data = "Connected to device";
    
    ROS_INFO ("%s", msg.data.c_str());
    chatter_pub.publish (msg);
    
    ros::spinOnce();
    
    int count = 0;
    while (ros::ok()) {
    
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    
    return 0;
}