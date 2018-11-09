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
	std::unordered_map<std::string, int>::iterator it = wordMap.find("Fourth");
	// .erase()
	// return => number of elements deleted
	if(it != wordMap.end())
		wordMap.erase(it);
	// display contents 
	for(std::pair<std::string, int> element : wordMap)
	{ std::cout << element.first << " :: " << element.second << std::endl; }
	std::cout << "******************************" << std::endl;

	// reset it to beginning 
	it = wordMap.begin();
	while(it != wordMap.end())
	{
		if(it->second == 2) break;
		++it;
	}
	if(it != wordMap.end()) wordMap.erase(it);
	// display contents 
	for(std::pair<std::string, int> element : wordMap)
	{ std::cout << element.first << " :: " << element.second << std::endl; }
	std::cout << "******************************" << std::endl;

	std::unordered_map<std::string, int> name_age({
					{"Philip Van Kampen",40},
					{"Amy Beth Hart",52},
					{"Maggie Hart",28},
					{"Seth Hart",26},
					});
	for(std::pair<std::string, int> element : name_age)
	{ std::cout << "Name: " << element.first << std::endl
			    << "Age : " << element.second << std::endl; }
	std::cout << "******************************" << std::endl;



	return 0;
}
