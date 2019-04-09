//由于deque是双向队列 所以有push_front方法 而 vector 则没有这种插入方法
#include <deque>
#include <iostream>
int main()
{
	std::deque<double>coll;
	for(int i=0 ; i< 10;i++)
	{
		coll.push_back(i+1);
		coll.push_front(i+1);
	}
	for(int j=0;j<coll.size();j++)
		std::cout<<coll[j]<<std::endl;
}