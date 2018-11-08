/*
Next permutation describtions:
Implement next permutation,which reaerranges numbers into the lexicographically next greater permutation of numbers,
if such arrangement is not possible,it must rearrange it as the lowest possible  order(ie,sorted in ascending order).
the reolacement must be in-place , do noe allocate extra memory.
Here are some examples.Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
class solution_one
{
public:
  void nextPermutation(std::vector<int> & num)
  {
    next_permutation(num.begin(),num.end());
  }
  template<typename BidiIt>
  bool next_permutation(BidiIt first,BidiIt last)
  {
    const auto rfirst = std::reverse_iterator<BidiIt>(last);
    const auto rlast = std::reverse_iterator<BidiIt>(first);
    auto pivot = next(rfirst);
    while(pivot != rlast and !(*pivot<*std::prev(pivot)))
           ++pivot;
    if(pivot == rfirst)
      {
          std::reverse(rfirst,rlast);
          return false;
      }
      auto change = find_if(rfirst,pivot,std::bind1st(std::less<int>(),*pivot));
      std::swap(*change,*pivot);
      std::reverse(rfirst,pivot);
      return true;
  }
};
