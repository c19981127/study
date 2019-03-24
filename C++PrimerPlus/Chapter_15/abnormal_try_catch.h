#ifndef _ABNORMAL_TRY_CATCH_H_
#define _ABNORMAL_TRY_CATCH_H_
#include <iostream>
#include <cstdlib>
#include <cfloat>
double error1(double x ,double y)// the problem will shutdown at line:abort()
{
  if(x == -y)
  {
    std::cout<<"the arguments are not allowed"<<std::endl;
    abort();
  }
  return 2*x*y/(x+y);
}
bool error2(double x , double y,double & z)
{
  if(x == -y)
  {
    z = DBL_MAX;
    return false;
  }
  else
  {
    z = 2*x*y/(x+y);
    return true;
  }
}
double error3(double x ,double y)
{
  if(x == -y)
    throw "the arguments are not allowed";
  return 2*x*y/(x+y);
}
#endif
