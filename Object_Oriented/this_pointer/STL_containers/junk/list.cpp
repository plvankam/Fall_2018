#include<iostream>
#include<list>

int main()
{

	std::list<int> listOfNumbers;

	// inserting elements 
	listOfNumbers.push_back(5);
	listOfNumbers.push_back(6);

	// inserting elements at front
	listOfNumbers.push_front(2);
	listOfNumbers.push_front(1);

	// iterating over list 
	std::list<int>::iterator it;
	for(it  = listOfNumbers.begin();
		it != listOfNumbers.end();
		++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

	it = listOfNumbers.begin();
	it++; 
	it++; 
	it++; 
	listOfNumbers.insert(it, 45);
	for(it  = listOfNumbers.begin();
		it != listOfNumbers.end();
		++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

	return 0;
}
