//in this file we use detach() to part the thread for the main thread
//in line 17  we used a car i which will destroyed brfore the using of the thread
//the result is not forecastable
#include <iostream>
#include <thread>
struct func
{
  int & i;
  func(int & i) : i(i) {};
  void do_somework(int i)
  {
    std::cout<<i<<std::endl;
  }
  void operator ()()
  {
    for(unsigned j = 0; j<=1000000;j++)
    {
      do_somework(i);   //there is a problem : we used var i
    }
  }
};
int main()
{
  int some_locate_sate = 0;
  func  my_func(some_locate_sate);
  std::thread t(my_func);
  t.detach();
  //t.join();  the program runs normally by using t.join()
  exit(EXIT_SUCCESS);
}
