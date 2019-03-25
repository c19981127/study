//in this program we use unique_ptr instread of auto_ptr
//the file is same to "auto_ptr.cpp" but  in this file  the complier gets the
//error at line 14
//because the complier thought it was not allowed
//this is why C++ 11 gives up auto_ptr
#include <iostream>
#include <memory>
std::unique_ptr<double> get_unique_ptr();
int main()
{
  std::unique_ptr<double> num1(new double);
  *num1 = 100;
  std::unique_ptr<double> num2(new double);
  *num2 = 200;
  num2 = num1;   //here it is not allowed
  num2 = get_unique_ptr();//here it is allowed because the temp will be
                          //destroyed after the function finishs;
  std::cout<<*num2<<" "<<*num1<<std::endl;
  return 0;
}
std::unique_ptr<double> get_unique_ptr()
{
  std::unique_ptr<double> temp(new double);
  return temp;
}
