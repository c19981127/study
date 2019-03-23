#ifndef _PRIVATE_INHERITANCE_H_
#define _PRIVATE_INHERITANCE_H_
#include <iostream>
#include <string>
class father
{
private:
  int age;
  std::string name;
public:
  father();
  father(int age_,std::string name_);
  void set_age(int age_);
  void set_name(std::string name_);
  void show_father();
  virtual ~father();
};
class son : private father
{
public:
  void show() {father::show_father();}
  ~son();
};
#endif
