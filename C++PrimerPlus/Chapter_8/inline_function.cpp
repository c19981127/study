#include <iostream>
#include <ctime>
inline void inline_show()
{
  std::cout<<"this is in inlineFunction"<<std::endl;
}
void show()
{
  std::cout<<"this is the normal Function"<<std::endl;
}
int main()
{
  long int i=10000000;
  time_t inline_start = time(NULL);
  for(;i>=0;i--)
  {
      inline_show();
  }
  time_t inline_end = time(NULL);

  time_t normal_start = time(NULL);
  for(long int x = 10000000;x>=0;x--)
  {
    show();
  }
  time_t normal_end = time(NULL);
  std::cout<<"inline_show's time :"<<difftime(inline_end,inline_start)<<"s"<<std::endl;
  std::cout<<"normal_show's time :"<<difftime(normal_end,normal_start)<<"s"<<std::endl;

  exit(EXIT_SUCCESS);

}
