#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
std::vector<int> test = {1,4,3,5,7};
class solution
{
public:
   std::vector<int> sum_closest(std::vector<int> a,int target)
   {
     std::vector<int> result;
     int close_number=1000;   //the solution_two and three  makes the colse_number INT_MAX
     int test_number = 0;
     for(auto A = a.begin();A<a.end()-2;A++)
     {
       for(auto B =A+1;B<a.end()-1;B++)
       {
          for(auto C = B+1;C<a.end();C++)
          {
            test_number = abs(*A+*B+*C-target);
            if(test_number<close_number)
              {
                close_number = test_number;
                result= {*A,*B,*C};
              }
          }
       }
     }
     std::cout<<close_number<<std::endl;
     return result;
   }
   void show(std::vector<int> a)
   {
     for(auto A = a.begin();A<a.end();A++)
        std::cout<<*A;
     std::cout<<std::endl;
   }
};
class solution_two
{
public:
  int sum_closest(std::vector<int> & num,int target)
  {
    int result = 0 ;
    int min_gap = INT_MAX;
    std::sort(num.begin(),num.end());
    for(auto a = num.begin();a!=prev(num.end(),2);a = upper_bound(a,prev(num.end(),2),*a))//why not use a++ ??
    {                                                               //here i try change to a++ and the result is the same
      auto b = next(a);
      auto c = prev(num.end());
      while(b<c)
      {
        const int sum = *a+*b+*c;
        const int gap = abs(sum-target);
        if(gap < min_gap)
        {
          result = sum;
          min_gap = gap;
        }
        if(sum<target) ++b;
        else           --c;
      }
    }
    return result;
  }
};
class solution_three
{
public:
  int sum_closest(std::vector<int> & num, int target)
  {
    int result = 0;
    int min_gap =INT_MAX;
    std::sort(num.begin(),num.end());
    for(auto a = num.begin();a!= prev(num.end(),2);a = upper_bound(a,prev(num.end(),2),*a))
    {
      auto b = next(a);
      auto c = std::prev(num.end());
      while(b<c)
      {
        const int sum = *a+*b+*c ;
        const int gap = abs(sum-target);
        if(gap < min_gap)
        {
          result = sum;
          min_gap = gap;
        }
        if(sum<target)
          b = upper_bound(b,c,*b); //b++ they are the same!
        else
          c = c-1;  //std::prev(lower_bound(b,c,*c));
      }
    }
    return result;
  }
};
int main()
{
  solution cheng;
  cheng.show(cheng.sum_closest(test,9));
  solution_two cong;
  std::cout<<cong.sum_closest(test,9)<<std::endl;
  solution_three woca;
  std::cout<<woca.sum_closest(test,9)<<std::endl;
  return 0;
}
