#include <iostream>
#include <thread>
void HelloWorld()
{
  std::cout<<"Hello World"<<std::endl;
}
int main()
{
  std::thread t(HelloWorld);
  t.join();
  exit(EXIT_SUCCESS);
}
