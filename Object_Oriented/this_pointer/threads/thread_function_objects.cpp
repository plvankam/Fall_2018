#include<iostream>
#include<thread>

class DisplayThread
{
public:
	void operator()(){
		for(int i = 0; i < 100; ++i) {
				std::cout << "Display Thread Executing" << std::endl;
		}
	}
};

int main()
{

	return 0;
}
