#include<iostream>
#include<unordered_map>
#include<string>


#define CHECK_HASH_ELEMENT_ADDED(x)     if(!x.second) std::cout << "Element not added: " << std::endl;

int main()
{


	// creating an empty umap
	std::unordered_map<std::string, int> wordMap;
	// insert 
	wordMap.insert({
					{"First",1},
					{"Second",2},
					{"Third",3},
					});

	typedef std::unordered_map<std::string, int>::iterator UOMIterator;
	std::pair<UOMIterator, bool> result;
	// inserting an element through pair
	result = wordMap.insert(std::make_pair<std::string, int>("Second", 6));
	CHECK_HASH_ELEMENT_ADDED(result) 
    result = wordMap.insert(std::make_pair<std::string, int>("Fourth", 4));
	CHECK_HASH_ELEMENT_ADDED(result)

	for(std::pair<std::string, int> element : wordMap)
		std::cout << element.first << " :: " << element.second << std::endl;	
	
	return 0;
}


