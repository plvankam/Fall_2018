#include<iostream>
#include<thread>
class DisplayThread
{
	public:
	    void operator()()
	    {
	    	for (int i = 0; i < 100; ++i)
	    	{
	    		std::cout << "Display Thread Executing" << std::endl;
	    	}
	    }
};

int main()
{

	std::thread threadObj( (DisplayThread()) );
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "Display From Main Thread" << std::endl;
	}
	std::cout << "Waiting for thread." << std::endl;
	threadObj.join();
	std::cout << "Exiting from Main Thread." << std::endl;

	return 0;
}
