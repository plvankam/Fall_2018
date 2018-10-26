#include<iostream>

struct MyFunctor
{
public:
	int operator()(int a, int b) {return a + b;}
};


int main()
{

	MyFunctor myFunc;
	std::cout << "myFunc(2,3) = " << myFunc(2,3) << std::endl;

	return 0;
}
