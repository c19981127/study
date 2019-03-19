#include "Overload.h"
#include <iostream>
overload::overload()
{
  age = 100;
}
overload::overload(int x)
{
  age = x;
}
overload & overload::operator+(overload &a)
{
  this->age = this->age+a.age;
  return *this;
}
overload & operator+(int x , overload & a)
{
  a.age = x + a.age;
  return a;
}
void overload::show()
{
  std::cout<<age<<std::endl;
}
/*
overload::operator double() const
{
  return double (age);
}*/
overload::~overload()
{
  std::cout<<"the class has been destroyed"<<std::endl;
}
