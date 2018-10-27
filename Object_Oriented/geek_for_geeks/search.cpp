#include<iostream>
#include<algorithm>

void show(int a[], size_t size)
{
	for(int i; i < size; ++i) std::cout << a[i] << " ";
}


int main()
{
	
	int a[10] = {1,5,8,9,6,7,3,4,2,0};
	size_t size = sizeof(a)/sizeof(int);
	std::sort(a, a + size);
	show(a, size);

	// binary search
	if(std::binary_search(a, a + size, 2))
        std::cout << "\nElement found in the array";
    else
        std::cout << "\nElement not found in the array"; 

	return 0;
}
