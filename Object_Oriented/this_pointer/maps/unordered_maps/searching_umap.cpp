#include<iostream>
#include<unordered_map>
#include<string>

int main()
{

	// init a map
	std::unordered_map<std::string, int> wordMap(
					{
					{"First",1},
					{"Second",2},
					{"Third",3},
					}
					);
	// declare an iterator 
	std::unordered_map<std::string, int>::iterator it;

	// find()
	it = wordMap.find("First");

	if(it != wordMap.end()) 
		std::cout << it->first << " :: "
				  << it->second << std::endl;
	else
		std::cout << "Element not found" << std::endl;


	return 0;
}
