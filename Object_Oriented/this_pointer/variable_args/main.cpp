#include<iostream>
#include<stdarg.h>

void findSum(int numOfElements, ...)
{
	// create the var list
    va_list varList;
	// start List 
	va_start(varList, numOfElements);
	int sum = 0;
	for(int i = 0; i < numOfElements; ++i)
	{
		int x = va_arg(varList, int);
		sum += x;
	}	
	std::cout << "Sum = " << sum << std::endl;
	// end list 
	va_end(varList);
}

int main()
{

	findSum(3,1,2,3);
	findSum(4,5,6,7,8);

	return 0;
}
