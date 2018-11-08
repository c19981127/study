/*
Search in Rotated Sorted array
describtion:
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e,0,1,2,4,5,6,7 might become 4,5,6,7,0,1,2)
You are  given a target value te search. If found in the array return its index,otherwise return -1
You may assume no duplicates exists in the array
*/
#include <iostream>
class solution_one    //只能适用于递增数列二分法求解？？？？？ what？？
{                     //日后有机会回头来做这个
  public:
    int search(int A[],int n,int target)
    {
     int frist =0;
     int last=n;
     while(frist!=last)
    {
      const int mid =(frist+last)/2;
      if(A[mid]==target)
        return mid;
      if(A[frist]<=A[mid])
      {
        if(A[frist]<=target && target <A[mid])
            last = mid;
        else
            frist=mid+1;
      }
      else
      {
        if(A[mid]<=target && target<A[last-1])
            frist = mid;
        else
            last=mid;
      }
    }
    return -1;
    }

};
int main()
{
  int A[5] = {1,3,4,6,7};
  solution_one cheng;
  std::cout<<cheng.search(A,5,3)<<std::endl;
  return 0;
}
