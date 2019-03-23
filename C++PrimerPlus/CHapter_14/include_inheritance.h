#ifndef _INCLUDE_INHERITANCE_H_
#define _INCLUDE_INHERITANCE_H_
#include <iostream>
#include <string>
#include <valarray>
class father
{
private:
  int age;
  std::string name;
  std::valarray <double> money;
public:
  father();
  father(int age_,std::string name_,std::valarray <double> money_);
  void set_age(int age_);
  void set_name(std::string name_);
  void set_money(std::valarray <double> money_);
  double avarge();
  void show_father();
  ~father();
};
#endif
