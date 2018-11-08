/*
Remove Duplicates from Sorted Array 2
describtion :
Follow up for "RemoveDuplicates" : What if Duplicates are allowed at most twoce ??
For example , given  sorted Array [1,1,1,2,2,3]
Your function should return length =5 and the Array is now [1,1,2,2,3]
*/
#include <iostream>
class solution_one    //自己的方法 直接遍历数组
{
public:
  int Remove_Duplicates_Plus(int A[] ,int n)
  {
     if(n==0)
      return 0;
     int index = n;
    for(int i=0;i<=n-1;i++)
    {
      int k =i;
      if(A[k]==A[i+1])     //在已经有两个的情况下  就可以执行后面的操作了
      {
        for(;i<=n-1;i++)
        {
          if(A[k]==A[i])
              index--;
        }
      }
    }
    return index;
  }
};
class solution_two    //这里有一些问题，貌似不符合题目的意思
{                     //题目要求的是 最多出现两次 ，而这里给出的解决方法，貌似是理解成
public:               //最多只能有两个相邻的元素相同 即可以忍受类似[1,3,3,5,3,5,1,5]
                      //这种情况下 返回数组的长度是不变的
  int Remove_Duplicates_Plus(int A[],int n)
  {
     if(n==0) return 0;

     int occur =1;
     int index =0;
     for(int i=1;i<n;i++)
     {
       if(A[index]==A[i])
          {
              if(occur<2)
              {
                A[++index]=A[i];
                occur++;
              }
          }
        else
        {
          A[++index] =A[i];
          occur=1;
        }
     }
     return index+1;
  }
};
class solution_three     //这种就类似解法二 这个解决的是一个连续的问题 并不能分散开
{
public:
  int Remove_Duplicates_Plus(int A[],int n)
  {
    int index =0;
    for(int i=0;i<n;++i) //++i 就是先返回i+1 的结果 然后i=i+1
    {
      if(i>0 && i<n-1 && A[i]==A[i-1] && A[i]==A[i+1])
        continue;
      A[index++]=A[i];
    }
    return index;
  }
};
int main()
{
  int A[10] = {1,2,3,4,3,3,2,2,3,5};
  solution_one cheng;
  solution_two cheng_two;
  solution_three cheng_three;
  std::cout<<cheng.Remove_Duplicates_Plus(A,10)<<std::endl;  //return index =7;
  std::cout<<cheng_two.Remove_Duplicates_Plus(A,10)<<std::endl; //return index=10;
  std::cout<<cheng_three.Remove_Duplicates_Plus(A,10)<<std::endl; //return index=10;
  return 0;
}
