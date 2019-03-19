#include <vector>  //包含vector
#include <iostream>
#include <algorithm>  //包含STL 算法部分
#include <iterator>   //包含迭代器
#include <deque>      //包含deque  双向队列
#include <list>       //包含list  双向链表
#include <queue>      //比deque要求更强，不能随即访问，只能两段访问的队列
#include <stack>      //包含stack  不允许随即访问栈元素 ，不允许便利，只允许弹出，压入等操作
#include <array>      //C++ 11标准  包含基本的 数组array 类
//STL还有四种关联容器 set ,multiset,map,multimap,分别包含头文件如下
//set 键和值一一对应  multiset 可能多个值的键相同 键和值的类型相同
//map 键和值一一对应  multimap 可能多个值的键相同 键和值的类型不相同
#include <map>
#include <set>
typedef double * iterator;
iterator find_all(iterator ar,int n,const double & val);    //迭代器模板  函数
int main()
{

  double  a[10]={1,2,3,4,5,6,7,8,9,10};   //指针用于迭代器
  std::vector<double> b(10);
  copy(a,a+10,b.begin());

  std::ostream_iterator<int,char> out_liter(std::cout,"  "); //容器ostream_iterator
  *out_liter++ = 15;
  copy(a,a+10,out_liter);    //输出到屏幕
  std::cout<<std::endl;

  copy(a,a+10,std::ostream_iterator<int,char>(std::cout," ")); //实际上与上三行一样的效果

  copy(std::istream_iterator<int,char>(std::cin),std::istream_iterator<int,char>(),a);//cin定义键盘输入到数组a中
  for(int i=0;i<=9;i++)                                                               //遇到不符合要求的输入停止
      std::cout<<a[i]<<"  ";
  std::cout<<std::endl;


  std::vector<double>::iterator  woqu;    //迭代器的应用
  for(woqu=b.begin();woqu!=b.end();woqu++)
    std::cout<<*woqu<<std::endl;

  copy(b.rbegin(),b.rend(),std::ostream_iterator<int,char>(std::cout,"  "));    //rbegin(),rend()函数支持反向输出

  for(double x : a) std::cout<<x<<std::endl;   //C++ 11新增的for循环  （此处报错 g++ -o iterator iterator.cpp -std=c++11 增加编译选项即可）
  std::cout<<find_all(a,10,100)<<std::endl;

  return 0;
}
iterator find_all(iterator ar,int n,const double & val)
{
  for(int i=0;i<n;i++,ar++)
      {
        if(*ar == val)
          return ar;
      }
  return NULL ;
}
