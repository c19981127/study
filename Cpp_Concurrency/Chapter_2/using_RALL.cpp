//Here we use RALL to wait for the thread to finish
#include <iostream>
#include <thread>
class thread_guard
{
  std::thread& t;
public:
  explicit thread_guard(std::thread & t_) : t(t_) {};
  ~thread_guard()
  {
    if(t.joinable())
    {
      t.join();
    }
  }
  thread_guard(thread_guard const&)=delete;
  thread_guard& operator=(thraed_guard const &)=delete;
};
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
  func my_func(some_locate_sate);
  std::thread my_thrad(my_func);
  thraed_guard g(my_thread);
  dO_something_in_current_thread();
}
