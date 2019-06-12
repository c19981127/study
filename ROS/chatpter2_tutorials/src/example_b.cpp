#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallBack(const std_msgs::String::ConstPtr &msg)
{
  ROS_INFO("i heard : [%s]",msg->data.c_str());
}
int main(int argc, char ** argv)
{
  ros::init(argc,argv,"example_b");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("message",1000,chatterCallBack);
  ros::spin();
  return 0;
}
