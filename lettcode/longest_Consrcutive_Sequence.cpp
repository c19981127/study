/*
Longest consecutive Sequence
describtion :
Given an ubsorted array of integers,find the length of Longest consecutive Sequence
For example.GIven  [100,4,200,1,3,2],the Longest consecutive elements Sequence id
[1,2,3,4].return its length 4/
YOur algorithm should run in O(n) complexity
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class solution_one
{
public:
  int Longest_consecutive_sequence(std::vector<int> const & n)
  {
    std::unordered_map<int,bool> used;

    for(auto i : n) used[i]= false;
    int longest = 0;
    for(auto i : n)
    {
      if(used[i])  continue;

      int length = 1;
      used[i]  = true;
      for(int j=i+1;used.find(j)!=used.end();++j)
      {
        used[j]= true;
        ++length;
      }
      for(int j=i-1;used.find(j)!=used.end();--j)  // 这里的end() 不是迭代器末尾的意思
      {                                             // find(j) 找到了 ‘j’ 返回指向 ‘j’的迭代器
        used[i] = true;                            // 找不到则返回end() 迭代器
        ++length;
      }
      longest = std::max(longest,length);
    }
    return longest;
  }
};
int main()
{
  std::vector<int> const A= {1,2,4,3,5,7};
  solution_one cheng;
  std::cout<<cheng.Longest_consecutive_sequence(A)<<std::endl;
  return 0;
}
