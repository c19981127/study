#include <iostream>
template <typename T>
void swap(T &a ,T &b)
{
  T temp ;
  temp = a;
  a = b;
  b=temp;
}
int main()
{
  int int_x,int_y;
  double double_x,double_y;
  swap(int_x,int_y);
  swap(double_x,double_y);
  return 0;
}
