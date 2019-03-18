#include <iostream>
void test(int a ,int b =1);
void test_2(int a ,int b =1;int c); //invaild
void test_3(int a ,int b =1,int c =1);//invaild
int main()
{
  test(100);
  test(100,100);
  test2(100,300,200); //complie error
  test2(199, ,200,); //complie error
  test_3(31);
  test_3(100,100);
}
