//Here we use try catch to mask sure the thread is joinable;
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
  int state = 0;
  func my_func(state);
  std::thread my_thrad(my_func);
  try
  {
    dO_something_in_current_thread();
  }
  catch(...)
  {
    t.join();
    throw();
  }
  t.join();
  return (EXIT_SUCCESS);
}
