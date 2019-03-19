#include "Class.h"
#include <iostream>
int main()
{
  test test_class(18,"china");
  test_class.set_age(10);
  test_class.set_name("chengpipi");
  test_class.show();

  test test_class_default;
  test_class_default.set_age(100);
  test_class_default.set_name("chengzi");
  test_class_default.show();

  test test_class_equal = test(); //there test() create a new test class then give it to
                                  //to test_class_equal ,then the  class created by test() was been destroyed
  test test_compare = test_class_default.compare(test_class);
  test_compare.show();
  return 0;
}
test::test()
{
  age = 0;
  name = "default";
}
test::test(int a , const std::string b)
{
  age = a;
  name = b;
}
void test::set_age(int a)
{
  age = a;
}
void test::set_name(const std::string name_)
{
  name = name_;
}
void test::show()
{
  std::cout<<age<<"   "<<name<<std::endl;
}
const test & test::compare(const test & s)
{
  if(this->age > s.age)
    return *this;
  else
    return s;
}
test::~test()
{
  std::cout<<"the class has been destroyed"<<std::endl;
}
