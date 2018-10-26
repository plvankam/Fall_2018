#include<iostream>
#include<utility>

int main()
{

	std::pair<int,char> PAIR1;
	PAIR1.first  = 100;
	PAIR1.second = 'G';

	std::cout << PAIR1.first  << " ";
	std::cout << PAIR1.second << " ";

	return 0;
}
