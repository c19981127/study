#include <iostream>
#include <vector>
#include <array>
#include <valarray>
#include <algorithm>
#include <initializer_list>  // initizlizer templates
using namespace std;
int main()
{
  vector<double> ved1(10),ved2(10),ved3(10);
  array<double,10> vod1,vod2;
  valarray<double> vad1(10),vad2(10),vad3(10);
  //assume that v(a,e,o)(1,2) have exactly value then if we need to add the
  //frist index and get the result to the frist array of third i can do these;

  /*vecctor as a part of STL*/
  transform(ved1.begin(),ved1.end(),ved2.begin(),ved2.end(),plus<double>());
  /*array is not a part of STL,bur some function could be used*/
  transform(vod1.begin(),vod1.end(),vod2.begin(),ved2.end(),plus<double>());
  /*valarray is not a part of STL ,no functions for it ,but it overloads  all Arithmetic operator*/
  /*valarray is a class so it has many functions like "sum(),size(),max(),log(),apply() and so on"*/
  vad3 = vad1+ vad2;
  /*valarray itself dong has STL functions like "end(),begin" ,but the C++ 11 gives some functions*/
  sort(begin(vad1),end(vad1)); //sort is  a Stl functions but C++11  could use  like this.
  vector<double> peyments {23.99,32.32,41,68};  //its fine ,the complier could transfor in to double
  //vector<int> test {12,32.3,41,31};   its not allowed ,because could not trans double to int
  return 0;
}
