#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class OddCounter
{
	    int m_Counter;
    public:
		int getCount()
		{
			return m_Counter;
		}
		void update(std::vector<int>& vec)
		{
			std::for_each(vec.begin(), vec.end(), [this](int element) {
								if (element % 2) ++m_Counter;
							});
		}
};

int main(int argc, char* argv[])
{

	// create vector
	std::vector<int> vec = {12,3,2,1,8,9,0,2,3,9,7};
	// create instance of OddCounter
	OddCounter counterObj;
	// update m_Counter
	counterObj.update(vec);
	// get count 
	int count = counterObj.getCount();
	// print out 
	std::cout << "Counter = " << count << std::endl;

	return 0;
}
