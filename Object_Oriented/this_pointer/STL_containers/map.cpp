#include<iostream>
#include<map>
#include<string>
#include<iterator>

int main()
{

	// create instance of std::map
	std::map<std::string, int> mapOfWords;
	// inserting data in std::map
	mapOfWords.insert(std::make_pair("earth",1));
	mapOfWords.insert(std::make_pair("moon" ,2));
	mapOfWords["sun"] = 3;
	mapOfWords["earth"] = 4;

	// iterator 
	std::map<std::string, int>::iterator it = mapOfWords.begin();
	while(it != mapOfWords.end()) {
		std::cout << it->first << " :: " << it->second << std::endl;	
		++it;
	}

	// deleting from map	
	it = mapOfWords.find("moon");
	mapOfWords.erase(it);

	// erase by key
	mapOfWords.erase("earth");

	it = mapOfWords.begin();
	while(it != mapOfWords.end()) {
		std::cout << it->first << " :: " << it->second << std::endl;	
		++it;
	}


	return 0;
}

