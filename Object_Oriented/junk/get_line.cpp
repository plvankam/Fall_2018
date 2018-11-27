#include<string>
#include<iostream>

int main()
{

	std::string str;
	std::cout << "Type a string: ";
	std::getline(std::cin, str);
	std::cout << "You typed: " << str << std::endl;

	return 0;
}
