#include <vector>
#include <iostream>
#include <algorithm>
void show(int a );
int main()
{
  std::vector<int> rating(5);
  rating[0]=10;
  for(std::vector<int>::iterator pa=rating.begin();pa!=rating.end();pa++)
      std::cout<<*pa<<std::endl;
  std::vector<int> cheng(5);
  rating.insert(rating.begin(),cheng.begin(),cheng.end()); //insert(1,2,3)把2.，3加入到1 的前面
  for(std::vector<int>::iterator pa=rating.begin();pa!=rating.end();pa++)
      std::cout<<*pa<<std::endl;
  for_each(rating.begin(),rating.end(),show);//for_each(区间左，区间右，执行函数)
/*
  std::vector<int>::iterator pd;
  pd = rating.begin();
  std::cout<<*pd<<std::endl;    迭代器
*/
  /*int c ;
  std::cin>>c;
  rating.push_back(c);
  std::cout<<rating[5]<<std::endl;    push_back()添加元素到容器末尾
*/
  /*rating.erase(rating.begin()-1,rating.begin()+4);   //删除元素 指定区间
  for( pd=rating.begin();pd!=rating.end();pd++)
      std::cout<<*pd<<std::endl;
*/  return 0;
}
void show(int a)
{
  std::cout<<a<<std::endl;
}
