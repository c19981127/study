/*
Remove Duplicates from an  sorted array
details:
   Given a sorted array, remove the Duplicates in place such that each element
appears only once and return the new length.
   Do not allocate extra space for another array,you should do this in a constant
memory.
  for example :
  give an input an array [1,2,2,4]
  your function show return 2 and now the array is[1,2,4]
*/
#include <iostream>
#include <algorithm>
class solution_one
{
public:
  int RemoveDuplicates(int A[],int n)
  {
    if(n==0) return 0;
    int index=0;
    for(int i=0;i<n;i++)
    {
      if(A[index]!=A[i])
          index++;
    }
    return index+1;
  }
};
class sulotion_two
{
public:
  int RemoveDuplicates(int A[],int n)
  {
    return std::distance(A,std::unique(A,A+n)); //distance（andress,andress)返回两个地址之间的距离
  }                                             //unique(andress,andress)左闭右开  去掉区间的相同的元素，返回处理后的尾地址
};
class sulotion_three
{
public:
  int RemoveDuplicates(int A[],int n)
     {
       return RemoveDuplicates(A,A+n,A)-A;
     }
  template<typename InIt ,typename OutIt>
  OutIt RemoveDuplicates(InIt frist,InIt last,OutIt output)
  {
    while(frist!=last)
     {
       *output++=*frist;
       frist = std::find_if(frist,last,std::bind1st(std::not_equal_to<int>(),*frist));  //find_if（andress ,andress,int） 返回区间内第一个等于三的元素地址
     }
    return output;
  }
};
