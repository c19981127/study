#include <iostream>
template <typename T >
class base_template
{
private:
  T name;
  T age;
public:
  base_template() {this->name =(T)100;this->age=T(68);std::cout<<"the base_template class has been made"<<std::endl;}
  void show_all () {std::cout<<this->name<<" "<<this->age<<std::endl;}
  ~base_template() {std::cout<<"the base_template class has been destoryed"<<std::endl;}
};
class base
{
private:
  int number ;
public:
  int woca ;
  base() {this->number=100;std::cout<<"the base class has been made"<<std::endl;}
  virtual void show_woca() {std::cout<<this->woca<<std::endl;}
  virtual void show_number() {std::cout<<this->number<<std::endl;}
  virtual ~base() {std::cout<<"the base class has been destoryed"<<std::endl;}
};
class base_two
{
private:
  int number;
public:
  int woca;
  base_two() {std::cout<<"the base_two class has been made"<<std::endl;}
  void show_number() {std::cout<<this->number<<std::endl;}
  virtual ~base_two() {std::cout<<"the base_two class has been destoryed"<<std::endl;}
};
class base_public : public base
{
private:
  int age;
public:
  base_public() {std::cout<<"the base_public class has been made "<<std::endl;}
  void show_number() {base::show_number();}
  void show_woca() {std::cout<<this->woca<<std::endl;}
  void show_age() {std::cout<<this->age<<std::endl;}
  ~base_public() {std::cout<<"the base_public class has been destoryed"<<std::endl;}
};
class base_protect : protected base
{
private:
  int age;
public:
  base_protect() {std::cout<<"the base_protect class has been made"<<std::endl;}
  void show_number() {base::show_number();}
  void show_woca() {std::cout<<this->woca<<std::endl;}
  void show_age() {std::cout<<this->age<<std::endl;}
  ~base_protect () {std::cout<<"the base_protect class has been destoryed"<<std::endl;}
};
class base_private : private base
{
private:
  int age;
public:
  base_private() {std::cout<<"the base_private class has been made"<<std::endl;}
  void show_number() {base::show_number();}
  void show_woca () {std::cout<<this->woca<<std::endl;}
  void show_age() {std::cout<<this->age<<std::endl;}
  ~base_private() {std::cout<<"the base_private class has been destoryed"<<std::endl;}
};
class base_mul : public base , public base_two
{
private:
  int age;
public:
  ~base_mul() {std::cout<<"the base_mul class has been destoryed"<<std::endl;}
  void show_number() {base::show_number();base_two::show_number();}
  void show_woca() {std::cout<<base::woca<<base_two::woca<<std::endl;}
} ;
int main()
{
  base A;
  base_public B;
  base_private C;
  base_protect D;
  A.show_number();
  base_template <char> X;
  X.show_all();
  return 0;
}
