#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory> //智能指针
class TV
{
private:
  int age;
  int number;
  friend class remote;
public:
  TV() {this->number=100;this->age=1000;std::cout<<"the TV class has been made"<<std::endl;}
  void show_all() {std::cout<<this->age<<" "<<this->number<<std::endl;}
  friend void show_tv(TV & p) {std::cout<<p.age<<" "<<p.number<<std::endl;}
  virtual ~TV() {std::cout<<"the TV class has been destoryed"<<std::endl;}
};
class remote
{
public:
  void show_TV(TV & a) {std::cout<<a.age<<" "<<a.number<<std::endl;}
  remote() {std::cout<<"the remote class has been created"<<std::endl;}
  virtual ~remote() {std::cout<<"the remote class has been destoryed"<<std::endl;}
};
int main()
{
  char  woca[5] = {'a','b','c','d','e'};
  std::string six(woca+1,woca+4);
  std::string seven = "bcd";
  if(seven==six)
    std::cout<<"the same string"<<std::endl;
  std::auto_ptr <double> third(new double);
  std::auto_ptr <double> forth(new double);
  third= forth; //auto_ptr允许指向同一个目标的智能指针之间相互复制
  std::unique_ptr <std::string> frist(new std::string);
  std::unique_ptr <std::string> second(new std::string);
  //frist = second;//unique_ptr 不允许指向同一个目标的智能指针之间相互复制
  std::cout<<six<<std::endl;
  TV * A = new TV;
  remote * B = new remote;
  A = dynamic_cast<TV *>(B);
  std::cout<<A<<std::endl;
  TV one;
  remote two;
  two.show_TV(one);
  show_tv(one);
  return 0;
}
