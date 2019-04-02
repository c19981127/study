#include <memory>
#include <iostream>
int main()
{
  //std::auto_ptr<int> test_int = new int;  //this is not allowed
  std::auto_ptr<int> test_int_2(new int);
  std::auto_ptr<int> test_int(new int);
  *test_int = 100;
  *test_int_2=200;
  std::cout<<*test_int<<" "<<*test_int_2<<std::endl;

  test_int_2 = test_int;
  //std::cout<<*test_int<<std::endl; this is not allowed because the test_int is null now
  std::cout<<*test_int_2<<std::endl;
}
