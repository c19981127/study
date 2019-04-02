#include <utility>
#include <iostream>
int main()
{
  std::pair<int, int>test_pair(100,200);
  std::cout<<test_pair.first<<" "<<test_pair.second<<std::endl;
}
