#include<iostream>
#include<vector>

int main()
{

	std::vector<int> vecOfInts;
	for(int i = 0; i < 10; ++i) vecOfInts.push_back(i + 1);
	std::vector<int>::iterator it;
	it = vecOfInts.begin();
	vecOfInts.insert(it + 4, 12);
	vecOfInts.insert(it, vecOfInts.begin(), vecOfInts.end());
	for(it = vecOfInts.begin();
		it != vecOfInts.end(); ++it) {
			std::cout << *it << std::endl;
	}

	return 0;
}
