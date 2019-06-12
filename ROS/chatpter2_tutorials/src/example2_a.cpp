#include "ros/ros.h"
#include "chatpter2_tutorials/chapter2_srv1.h"
#include "std_msgs/String.h"
#include <stdio.h>
bool add(chatpter2_tutorials::chapter2_srv1::Request &req,chatpter2_tutorials::chapter2_srv1::Request &res)
{
  res.sum = req.A+req.B+req.C;
  ROS_INFO("request : A=%ld,B=%d,C=%d",(int)req.A,(int)req.B,(int)req.C);
  ROS_INFO("sum [%d]",(int)res.sum);
  return true;
}
int main(int argc,char ** argv)
{
  ros::init(argc,argv,"add_3_inits_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_3_ints",*add);
  ROS_INFO("Ready to add 3 ints .");
  ros::spin();
  return 0;
}
