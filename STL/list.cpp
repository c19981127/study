#include <iostream>
#include <list>
int main()
{
	std::list<double>coll;
	for(int i=0;i<10;i++)
	{
		coll.push_back(i+1);
	}
	while(!coll.empty())
	{
		std::cout<<coll.front()<<std::endl;   //show the first number of the list
		coll.pop_front();  //delete the frist  number
		//std::cout<<coll.pop_front();  you can not do this because pop_front does not return a number
	}
}