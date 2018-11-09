#include<iostream>
#include<unordered_map>
#include<string>

int main()
{

	// create an empty unordered map
	std::unordered_map<std::string, int> wordMap;
	// insert few elements in map 
	wordMap.insert({"first", 1});
	wordMap.insert({"second", 2});
	wordMap.insert({"third", 3});

	// overwrite value of an element
	wordMap["third"] = 8;

	for(std::pair<std::string, int> element : wordMap) 
			std::cout << element.first << " :: " << element.second << std::endl;

	return 0;
}
