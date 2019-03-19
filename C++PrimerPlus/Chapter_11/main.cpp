#include "Overload.h"
#include "Overload.cpp"
#include <iostream>
int main()
{
  overload a(100);
  overload b(200);
  overload test = a+b;
  test.show();
  overload test_friend = 2+a;
  test_friend.show();

  //int test;
  //test = test_friend;
  //std::cout<<test<<std::endl;
  return 0;
}
