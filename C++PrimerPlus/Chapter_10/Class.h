#ifndef CLASS_H_
#define CLASS_H_
#include <string>
class test
{
private:
  int age;
  std::string name;
public:
  test();
  test(int a , const std::string b);
  void set_age(int a);
  void set_name(const std::string name_);
  void show();
  const test & compare(const test & s);
  ~test();
};
#endif
