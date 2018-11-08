/*
Remove element:
describtions:
given an array and a value,remove all instance of that value in place and return the new length
the order of elements can be changed.it dosen't matter what you leave beyond the new length
*/
#include <iostream>
#include <algorithm>
class solution_one
{
public:
  int Remove_elements(int A[],int n ,int elem)
  {
    int index = 0;
    for(int i=0;i<n;i++)
      if(A[index] != elem)
        A[index++] = elem;
    return index;
  }
};
class solution_two
{
public:
  int  Remove_elements(int A[],int n, int elem)
  {
     return std::distance(A,std::remove(A,A+n,elem));//remove (a,b,c) "delete"  all c between a and b then return the end adress
  }                                                  //but it not delete it ,just pull they to original array's end
};                                                   //for example  A={1,2,4,5,6,7,5,7} and remove(A,A+8,5) ,then the array was  changed A = {1,2,3,4,6,7,7,5,5,}
                                                    //return the  adress of the second "7"
