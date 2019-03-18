#include <iostream>
void swapr(double & a ,double & b)
{
  double temp;
  temp  = a;
  a= b;
  b=temp;
}
int main()
{
  double x =100, y = 200;
  std::cout<<"X= "<<x<<"Y= "<<y<<std::endl;
  swapr(x,y);
  std::cout<<"X= "<<x<<"Y= "<<y<<std::endl;

//when i compile this file , the cpomplier show this is an error in line 19
//mark here 
  int  a = 100;
  int  b = 200;
  std::cout<<"X= "<<a<<"Y= "<<b<<std::endl;
  swapr(a,b);
  std::cout<<"X= "<<a<<"Y= "<<b<<std::endl;
  return 0;
}
