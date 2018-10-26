#include<iostream>
#include<algorithm>

#define NEW_LINE std::cout << std::endl;

int main()
{

	int arr[] = {1,2,3,4,5};
	int mul = 0;
	std::cout << "mul = " << mul << std::endl;
	std::for_each(arr, arr + sizeof(arr)/sizeof(int), [&](int x) {
					mul = 3;
					std::cout << x << " ";});
	NEW_LINE
	std::cout << "mul = " << mul << std::endl;

	return 0;
}
