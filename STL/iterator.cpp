#include <iostream>
#include <vector>
#include <iterator>
int main()
{
	std::vector<int>coll;
	for(int i = 0; i<100;i++)
		coll.push_back(i+1);
	std::vector<int>::const_iterator pos;
	for(pos=coll.begin();pos!=coll.end();++pos)
		std::cout<<*pos<<"  ";
}