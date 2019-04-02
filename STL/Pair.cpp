#include <utility>
#include <iostream>
const std::pair<int,int> & get_Max(const std::pair<int ,int > & a ,const std::pair<int, int> & b);
void equal(std::pair<int, int > &a ,const std::pair<int,int> &b);
bool if_equal(const std::pair<int ,int>a ,const std::pair<int ,int>b);
int main()
{
  std::pair<int, int>test_pair(100,200);
  std::cout<<test_pair.first<<" "<<test_pair.second<<std::endl;

  std::pair<int,int> pair_one(100,100);
  std::pair<int,int> pair_two(200,200);
  std::cout<<"the bigger one's first and second of pair_one and pair_two are  "<<
  get_Max(pair_one, pair_two).first<<" "<<get_Max(pair_one, pair_two).second<<std::endl;

  std::cout<<"Before the equal function the pair_one are "<<pair_one.first<<" "<<pair_one.second<<std::endl;
  equal(pair_one,pair_two);
  std::cout<<"After the equal function the pait_one are "<<pair_one.first<<" "<<pair_one.second<<std::endl;

  if(if_equal(pair_one,pair_two))
    std::cout<<"the pair_one is equal to pair_two"<<std::endl;
  else
    std::cout<<"the pair_one is different from pair_two"<<std::endl;

  std::pair<int,int>init_pair; //here we init the pair to (0,0)
  std::cout<<"the init_pair is inited to "<<init_pair.first<<" "<<init_pair.second<<std::endl;


  std::make_pair(12, 13); //init a pair
}


const std::pair<int,int> & get_Max(const std::pair<int,int> &a ,const std::pair<int,int> & b)
{
  if(a.first >= b.first)
  {
    if(a.first > b.first)
      return a;
    else
      {
        if(a.second > b.second)
          return a;
        else
          return b;
      }
  }
  else
    return b;
}
void equal(std::pair<int,int> &a,const std::pair<int,int> &b)
{
  a.first = b.first;
  a.second = b.second;
}
bool if_equal(const std::pair<int,int> a ,const std::pair<int, int> b)
{
  if(a.first == b.first && a.second == b.second)
    return true;
  return false;
}
