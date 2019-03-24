#include "abnormal_try_catch.h"
int main()
{
  double x = 10.0;
  double y = -10.0;
  double z = 0.0;

  //std::cout<<"the error1 function shows :"<<error1(x,y)<<std::endl;

  std::cout<<"the error2 function shows :"<<error2(x,y,z)<<"  "<<z<<std::endl;

//below are  by using error3
  try
  {
    std::cout<<"the function error 3 shows :  ";
    z = error3(x,y);
  }
  catch(const char * s)
  {
    std::cout<<s<<std::endl;
  }

  return 0;
}
