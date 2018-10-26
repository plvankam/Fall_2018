#include<iostream>
#include<algorithm>

void show(int a[])
{
	for(int i; i < 10; ++i) std::cout << a[i] << " ";
}


int main()
{
	
	int a[10] = {1,5,8,9,6,7,3,4,2,0};
	show(a);
	std::cout << std::endl;
	std::sort(a, a + 10);
	show(a);

	return 0;
}
