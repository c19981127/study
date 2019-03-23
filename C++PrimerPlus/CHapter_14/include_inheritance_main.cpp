#include "include_inheritance.cpp"
std::valarray <double> data(1.0,8);
int main()
{
  father father_one;
  father_one.show_father();
  std::cout<<"the father_one's avarge is :"<<father_one.avarge()<<std::endl;

  father father_two(10,"Chengzi",data);
  father_two.show_father();
  std::cout<<"the father_two's avarge is :"<<father_two.avarge()<<std::endl;

  return 0;
}
