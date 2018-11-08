/*
sum
describtion :
Given an array S of n integers, are there  elements a,b,c,and d in S such that a+b+c+d = target??
Find alll unique quadruplets in the array which gives the sum of target.
Note:
elements in a quadruplets (a,b,c,d) must be in non-desecending order(ie,a<=b<=c<=d)
the solution set must not contain  duplicate quadruplets
for example :
Given S = {1,0,-1,0,-2,2} and target = 0;
A solution set is {-1,0,0,1},{-2,-1,1,2},{-2,0,0,2}
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
std::vector<int> A {1,0,-1,0,-2,2};
class solution_one
{
public:
  std::vector<std::vector<int>> sum (std::vector<int> & A ,int n, int target)
  {
    std::vector<std::vector<int>> result;
    std::sort(A.begin(),A.end());
    if(n<4)
      {
        std::cout<<"the length of the vector was less than 4"<<std::endl;
        return result;
      }
    if(n==4)
     {
        std::cout<<"the length is equal to 4"<<std::endl;
        if(A[0]+A[1]+A[2]+A[3]==target)
        {
           std::cout<<"the sum of all elements was equal to target"<<std::endl;
           result.push_back(A);
        }
        else
          std::cout<<"the sum of all elements was not equal to target"<<std::endl;
        return result;
     }
     for(auto a = A.begin();a<A.end()-3;a++)
        for(auto b = a+1;b<A.end()-2;b++)
          for(auto c=b+1;c<A.end()-1;c++)
              for(auto d=c+1;d<A.end();d++)
              {
                if(*a+*b+*c+*d==target)
                {
                  result.push_back({*a,*b,*c,*d});
                }
                else
                  continue;
              }
    return result;
  }
  void show(std::vector<std::vector<int> > result)
  {
    for(auto a = result.begin();a<result.end();a++)
      {
        for(auto b=(*a).begin();b<(*a).end();b++)
            std::cout<<*b<<" ";
        std::cout<<std::endl;
      }
  }
};
class solution_two
{
public:
  std::vector<std::vector<int>> sum (std::vector<int> & num , int target)
  {
    std::vector<std::vector<int>> result;
    if(num.size()<4) return result;
    std::sort(num.begin(),num.end());
    auto last = num.end();
    for(auto a = num.begin();a<prev(last,3);a=upper_bound(a,prev(last,3),*a))
      for(auto b = next(a);b<prev(last,2);b = upper_bound(b,prev(last,2),*b))
        for(auto c = next(b);c<prev(last);c=upper_bound(c,prev(last),*c))
            {
              const int d = target - *a -*b-*c;
              if(binary_search(next(c),last,d))
              result.push_back({*a,*b,*c,d});
            }
    return result;
  }
};
class solution_three
{
public:
  std::vector<std::vector<int>> sum (std::vector<int> & num, int target)
  {
    if(num.size()<4)  return std::vector<std::vector<int>> ();
    std::sort(num.begin(),num.end());
    std::map <int,std::vector<std::pair<int,int>>> cache;
    for(size_t a =0;a<num.size();++a)
     {
       for(size_t b = a+1;b<num.size();++b)
          cache[num[a]+num[b]].push_back(std::pair<int,int>(a,b));
     }
   std::set<std::vector<int>> result;
   for(size_t c=2;c<num.size();++c)
   {
     for(size_t d =c+1;d<num.size();++d)
     {
       const int key = target-num[c]-num[d];
       if(cache.find(key)!=cache.end())
       {
         for(size_t k=0;k<cache[key].size();++k)
         {
         if(c<=cache[key][k].second)  continue;
         result.insert(std::vector<int> {num[cache[key][k].first],num[cache[key][k].second],num[c],num[d]});
         }
       }
     }
   }
   return  std::vector<std::vector<int>> (result.begin(),result.end());
  }
};
int main()
{
  solution_one cheng;
  cheng.show(cheng.sum(A,6,0));
  return 0;
}
