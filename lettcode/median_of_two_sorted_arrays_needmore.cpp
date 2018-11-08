/*
Median if two sorted Arrays
describtion:
There are two sorted Arrays A and B of size m and n respectively.Find the median of the
two sorted arrays.the overall time complexity should be log(m+n);
*/
#include <iostream>
#include <algorithm>
class solution_one
{
public:
  int min(int m,int n)
  {
    return m>n ? n : m;
  }
  int Search_K(int A[],int m,int B[],int n,int k) //my solution is to get the number_K_max number of two Arrays
  {                                               //   (But it is wrong) i haven got a method to solve it.
    if(k>m+n)
      return -1;
    int   x = 1;
    int key = min(A[0],B[0]);
    int A_count =-1;
    int B_count =-1;
    for(;A_count<m && B_count<n;)
    {
      if((bool)(A_count=A_count+1) && A_count<m)
      {
      if(A[A_count]<key)
          x=x+1;
      else if(A[A_count]==key)
      {
         ;
      }
      else
      {
           A_count=A_count-1;
      }
      }

     if((bool)(B_count=B_count+1) && B_count<n)
     {
      if(B[B_count]<key)
          x=x+1;
      else if(B[B_count]==key)
      {
        ;
      }
      else
      {
        B_count=B_count-1;
      }
    }
    if(x==k)
      return key;
    key = min(A[A_count+1],B[B_count+1]);
   }
   return (-1);
 }
};
class sulotion_two
{
public:
  double Search_K(int A[],int m,int B[], int n)  //i got it that the function just gets the median of two arrays
  {
    int total = m+n;
    if(total &  0x1)   //按位与 判断奇偶数
    {
        return find_kth(A,m,B,n,total/2+1);
    }
    else
        return (find_kth(A,m,B,n,total/2)+find_kth(A,m,B,n,total/2+1))/2;

  }
private:
  static double find_kth(int A[],int m,int B[],int n,int k)
  {
    if(m>n) return find_kth(B,n,A,m,k);
    if(m==0) return B[k-1];
    if(k==1) return std::min(A[0],B[0]);

    int pa =std::min(k/2,m),pb = k-pa;
    if(A[pa-1]<B[pb-1])
        return find_kth(A+pa,m-pa,B,n,k-pa);
    else if (A[pa-1]>B[pb-1])
        return find_kth(A,m,B+pb,n-pb,k-pb);
    else
        return A[pa-1];
  }
};
int main()
{
  int A[5] = {1,2,3,4,5};
  int B[5] = {6,7,8,9,10};
  sulotion_two cheng;
  std::cout<<cheng.Search_K(A,5,B,5)<<std::endl;;
  return 0;
}
