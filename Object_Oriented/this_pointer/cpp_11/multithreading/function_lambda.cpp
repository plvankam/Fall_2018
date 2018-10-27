#include<iostream>
#include<thread>

int main()
{

	int x = 9;
	std::thread threadObj([](){
					for (int i = 0; i < 100; ++i)
					{
						std::cout << "Thread" << std::endl;
					}
					});
	for(int i = 0; i < 100; ++i)
	{
		std::cout << "Main" << std::endl;
	}
	std::cout << "Waiting for Thread to finish" << std::endl;
	threadObj.join();
	std::cout << "Exiting Program" << std::endl;

	return 0;
}
