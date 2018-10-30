#include<string>
#include<array>
#include<iostream>
#include<algorithm>

int main()
{

	std::array<int, 3> a1{{1,2,3}};
	std::array<int, 3> a2 = {1,2,3};
	std::array<std::string, 2> a3 = {std::string("a"),"b"};

	// container operations are supported 
	std::sort(a1.begin(), a1.end());

	std::cout << '\n';

	for(const auto& s: a3) std::cout << s << ' ';

	return 0;
}
