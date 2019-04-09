#include <iostream>
#include <map>
#include <string>
int main()
{
	std::map<std::string,int>coll;
	coll.insert(std::make_pair("china",100));
	coll.insert(std::make_pair("jap",160));
	coll.insert(std::make_pair("USA",80));
	coll.insert(std::make_pair("eng",70));
	coll.insert(std::make_pair("t",10));

	//another insert way 
	coll["tes"]=1000;

	std::map<std::string,int>::const_iterator pos;
	std::cout<<coll.size();
	for(pos=coll.begin();pos!=coll.end();++pos)
		std::cout<<pos->first<<" "<<pos->second<<std::endl;
}