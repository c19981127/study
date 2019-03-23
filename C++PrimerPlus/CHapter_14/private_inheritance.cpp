#include "private_inheritance.h"
father::father()
{
  age = 100;
  name = "NULL";
}
father::father(int age_, std::string name_)
{
  age = age_;
  name = name_;
}
void father::set_age(int age_)
{
  age =age_;
}
void father::set_name(std::string name_)
{
  name = name_;
}
void father::show_father()
{
  std::cout<<age <<"  "<<name<<std::endl;
}
father::~father()
{
  std::cout<<"the father class has been destroyed"<<std::endl;
}
son::~son()
{
  std::cout<<"the son class has been destroyed"<<std::endl;
}
