/*
sum_of_zero
describtions:
Given an  array  S of n integers, are there elemnents a,b,c in S that a+b+c=0?
find all unique triplets in the array which gives sum of zero.
*/
#include <iostream>    //关于本次算法中涉及的upper_bound lower_bound and binary_search 函数
#include <vector>      // 参考csdn   https://blog.csdn.net/u010700335/article/details/41323427
#include <algorithm>
const int A[10] = {1,2,3,4,5,-2,-3,-1,-4,9};
std::vector<int>A_vector {1,2,3,4,5,-2,-3,-1,-4,9};
class solution_one    //my algorithm is so easy,just three for circles.
{
public:
  void  sum_of_zero(const int A[],int n)
  {
    std::cout<<"the frist solution :"<<std::endl;
    if(n<3)
      {
        std::cout<<"the length of the array is less than Three"<<std::endl;
        return ;
      }
    for(int i=0;i<=n-3;i++)
      for(int j=i+1;j<=n-2;j++)
        for(int k=j+1;k<=n-1;k++)
          {
            if(A[i]+A[j]+A[k]==0)
                {
                  std::cout<<"now we get the numbers:"<<A[i]<<" "<<A[j]<<" "<<A[k]<<std::endl;
                }
          }
      return ;
  }
};
class solution_two
{
public:
  std::vector<std::vector<int> > sum_of_zero(std::vector<int> & num)
  {
    std::vector<std::vector<int>>result;
    if(num.size()<3) return result;
    std::sort(num.begin(),num.end());
    const int target =0;

    auto last = num.end();
    for(auto a = num.begin();a<prev(last,2);a=upper_bound(a,prev(last,2),*a))//upper_bound(a,b,c) 返回a，b之间内第一个大于c的元素
        {
          for(auto b = next(a);b<prev(last);b=upper_bound(b,prev(last),*b))//prev(a,b)返回位置a前的第b个元素
            {
              const int c = target - *a - *b;
              if(binary_search(next(b),last,c)) //binary_search(a,b,c)在区间(a,b)中找到c
                  result.push_back(std::vector<int>{*a,*b,c});
            }
        }
        return result;
  }
};
void show(std::vector<std::vector<int>> a);
int main()
{
  solution_one cheng ;
  cheng.sum_of_zero(A,10);
  solution_two cong;
  show(cong.sum_of_zero(A_vector));
  return 0;
}
void show(std::vector<std::vector<int>> a) //二位vector的遍历
{
  std::cout<<"the second solution :"<<std::endl;
  for(auto x=a.begin();x<a.end();x++)
  {
    std::cout<<"now we get the numbers :";
    for(auto k = (*x).begin();k<(*x).end();k++)
        std::cout<<*k<<" ";
    std::cout<<std::endl;
  }
}
