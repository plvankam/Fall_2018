// begin()
// end()
// rbegin()
// rend()
// CONSTANT
// cbegin()
// cend()
// crbegin()
// crend()

#include<iostream>
#include<vector>

#define NEW_LINE std::cout << std::endl;

int main()
{

	// vector
    std::vector<int> g1;

	// begin() end()
	for(int i = 1; i <= 5; ++i)                   g1.push_back(i);
	std::cout << ".begin()   <-> .end()   ==> ";
	for(auto i = g1.begin(); i != g1.end(); ++i)  std::cout << *i     <<   " ";
	NEW_LINE
	std::cout << ".cbegin()  <-> .cend()  ==> ";
	for(auto i = g1.cbegin(); i != g1.cend(); ++i)  std::cout << *i   <<   " "; 
	NEW_LINE
	std::cout << ".rbegin()  <-> .rend()  ==> ";
	for(auto i = g1.rbegin(); i != g1.rend(); ++i)  std::cout << *i   <<   " "; 
	NEW_LINE
	std::cout << ".crbegin() <-> .crend() ==> ";
	for(auto i = g1.crbegin(); i != g1.crend(); ++i)  std::cout << *i <<   " "; 
	NEW_LINE

	// copy
	std::vector<int> g2 = g1;
	for(int i = 0; i < g2.size(); ++i) std::cout << g2[i] << " ";
	NEW_LINE


	return 0;
}
