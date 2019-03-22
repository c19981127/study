#include "inheritance.h"
father::father()
{
  name = "father";
  age = 40;
}
father::father(int age_,std::string name_)
{
  age = age_;
  name = name_;
}
void father::set_age(int age_)
{
  age = age_;
}
void father::set_name(std::string name_)
{
  name = name_;
}
void father::show_f()
{
  std::cout<<"father_age  "<<age<<"  father_name  "<<name<<std::endl;
}
father::~father()
{
  std::cout<<"the father class has been destroyed"<<std::endl;
}
son::son()
{
  father();
  son_age = 10;
  son_name = "son";
}
son::son(int father_age_,std::string father_name_,int son_age_,std::string son_name_)
{
  father(father_age_,father_name_);
  son(son_age_,son_name_);
}
son::son(int son_age_,std::string son_name_)
{
  son_age = son_age_;
  son_name = son_name_;
}
void son::set_father_name(std::string name_)
{
  set_name(name_);
}
void son::set_father_age(int age_)
{
  set_age(age_);
}
void son::set_son_name(std::string name_)
{
  son_name = name_;
}
void son::set_son_age(int age_)
{
  son_age = age_;
}
void son::show()
{
  show_f();
  std::cout<<"son_name  "<<son_name<<"  son_age  "<<son_age<<std::endl;
}
son::~son()
{
  std::cout<<"the son class has been destroyed"<<std::endl;
}
