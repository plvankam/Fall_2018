#include<iostream>
#include<unordered_map>
#include<string>

int main()
{

	// init umap
	std::unordered_map<std::string, int> wordMap({
					{"First",1},
					{"Second",2},
					{"Third",3},
					{"Fourth",4},
					{"Fifth",5},
					});
	// .erase()
	// return => number of elements deleted
	if(1 == wordMap.erase("Second"))
		std::cout << "Element Deleted. " << std::endl;

	return 0;
}
