#include "MI.h"
#include <iostream>
father::father()
{
  age = 100;
}
father::father(int age_)
{
  age = age_;
}
void father::set_age(int age_)
{
  age = age_;
}
void father::show()
{
  std::cout<<"the father age is :"<<age<<std::endl;
}
father::~father()
{
  std::cout<<"the father class has been destroyed"<<std::endl;
}


son_one::son_one()
{
  father();
}
son_one::son_one(int age_)
{
  father::set_age(age_);
}
void son_one::set_age(int age_)
{
  father::set_age(age_);
}
void son_one::show()
{
  father::show();
}
son_one::~son_one()
{
  std::cout<<"the son_one class has been destroyed"<<std::endl;
}


son_two::son_two()
{
  father();
}
son_two::son_two(int age_)
{
  father::set_age(age_);
}
void son_two::set_age(int age_)
{
  father::set_age(age_);
}
void son_two::show()
{
  father::show();
}
son_two::~son_two()
{
  std::cout<<"the son_two class has been destroyed"<<std::endl;
}

son_son::son_son()
{
  son_one();
}
son_son::son_son(int age_)
{
  son_two::set_age(age_);
}
void son_son::set_age(int age_)
{
  son_one::set_age(age_);
}
void son_son::show()
{
  son_one::show();
}
son_son::~son_son()
{
  std::cout<<"the son_son class has been destroyed"<<std::endl;
}
