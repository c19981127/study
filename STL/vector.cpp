#include <vector>
#include <iostream>
int main()
{
	std::vector<int>coll;
	for(int i=0;i<6;i++)
		coll.push_back(i);
	for(int j=0;j<coll.size();j++)
		std::cout<<coll[j]<<std::endl;
}
