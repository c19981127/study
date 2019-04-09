//here you can not use push_back or push_front because you do now have permission to 
//decide where the number is
#include <set>
#include <iostream>
#include <iterator>
int main()
{
	std::set<int>coll;
	coll.insert(3);
	coll.insert(6);
	coll.insert(1);
	coll.insert(2);
	coll.insert(4);
	coll.insert(5);
	coll.insert(7);

	std::set<int>::const_iterator pos;
	for(pos=coll.begin();pos!=coll.end();++pos)
		std::cout<<*pos<<" ";
	std::cout<<std::endl;
}