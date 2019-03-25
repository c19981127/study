//if we use auto_ptr to equal num1 to num2 ,the complier will not
//get error .then when we run the program ,at line 14 ,the error comes with "sigement default"

//because when run to  the line 13  the num1 becomes unsure and num1 points to nowhere
#include <iostream>
#include <memory>
int main()
{
  std::auto_ptr<double> num1(new double);
  *num1 = 100;
  std::auto_ptr<double> num2(new double);
  *num2 = 200;
  num2 = num1;
  std::cout<<*num2<<" "<<*num2<<std::endl;
  return 0;
}
