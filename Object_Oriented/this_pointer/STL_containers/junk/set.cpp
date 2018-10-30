#include<iostream>
#include<set>

int main()
{

	std::set<std::string> setOfNumbers;

	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("first");

	std::cout << "Set Size = " << setOfNumbers.size() << std::endl;

	for(std::set<std::string>::iterator it = setOfNumbers.begin();
		it != setOfNumbers.end();
		++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	return 0;
}
