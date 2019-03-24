#include "friend_class.h"
#include <iostream>
father::father()
{
  age = 100;
}
father::father(int age_)
{
  age = age_;
}
void father::show() const 
{
  std::cout<<"the father age is :"<<age<<std::endl;
}
father::~father()
{
  std::cout<<"the father class has been destroyed"<<std::endl;
}
void son::show(const father  &t)
{
  t.show();
}
