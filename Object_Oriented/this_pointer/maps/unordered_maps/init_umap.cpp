#include<iostream>
#include<unordered_map>
#include<string>


#define STARRED_BREAK std::cout << "***************" << std::endl;

int main()
{

	//******************************
	// init unordered map
	std::unordered_map<std::string, int> wordMap(
					{
					{"First"  ,1},
					{"Second ",2},
					{"Third"  ,3}
					}
					);
	for(std::pair<std::string, int> element : wordMap)
	{
			std::cout << element.first  << " :: "
					  << element.second << std::endl;
	}
    
	STARRED_BREAK

	//******************************
	// init through std::pair
	std::unordered_map<std::string, int> wordMap_2(wordMap.begin(), wordMap.end());
	for(std::pair<std::string, int> element : wordMap_2)
	{
			std::cout << element.first  << " :: "
					  << element.second << std::endl;
	}

	STARRED_BREAK

	//******************************
	// init through std::pair
	std::unordered_map<std::string, int> wordMap_3(wordMap);
	for(std::pair<std::string, int> element : wordMap_3)
	{
			std::cout << element.first  << " :: "
					  << element.second << std::endl;
	}


	return 0;
}
