#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<iterator>
#include<algorithm>


int main()
{
	std::map<std::string, int> wordMap({
		{"is", 6},
		{"the", 5},
		{"hat", 9},
		{"at", 6}
	});	
	std::cout << "std::map Contents : Elements are in sorted order of Keys" << std::endl;
	std::for_each(wordMap.begin(), wordMap.end(), [](std::pair<std::string, int> elem){
					std::cout << elem.first << " :: " << elem.second << std::endl;
					});

	return 0;
}
