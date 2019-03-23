#include "include_inheritance.h"
father::father()
{
  age = 100;
  name = "NULLY";
  money = std::valarray <double> (2.0,8);
}
father::father(int age_,std::string name_,std::valarray <double> money_)
{
  age = age_;
  name = name_;
  money = money_;
}
void father::set_age(int age_)
{
  age = age_;
}
void father::set_name(std::string name_)
{
  name = name_;
}
void father::set_money(std::valarray <double> money_)
{
  money = money_;
}
double father::avarge()
{
  return money.sum()/money.size();
}
void father::show_father()
{
  std::cout<<"age: "<<age<<"  name: "<<name<<std::endl;
}
father::~father()
{
  std::cout<<"the father class has been destroyed"<<std::endl;
}
