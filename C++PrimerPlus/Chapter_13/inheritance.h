#include <iostream>
#include <string>
class father
{
private:
  int age;
  std::string name ;
public:
  father();
  father(int age_ , std::string name_);
  void set_age(int age_);
  void set_name(std::string name_);
  void show_f();
  virtual ~father();
};
class son : public father
{
private:
  int son_age;
  std::string son_name;
public:
  son();
  son(int father_age_,std::string father_name_,int son_age_,std::string son_name);
  son(int son_age_,std::string son_name_);
  void set_father_name(std::string name_);
  void set_father_age(int age_);
  void set_son_age(int age_);
  void set_son_name(std::string name_);
  void show();
  ~son();
};
