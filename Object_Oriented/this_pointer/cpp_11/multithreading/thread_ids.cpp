#include<iostream>
#include<thread>

void thread_function()
{
	std::cout << "Insdide Thread :: ID = " 
			  << std::this_thread::get_id() 
			  << std::endl;
}

int main()
{

	std::thread threadObj1(thread_function);
	std::thread threadObj2(thread_function);
	if(threadObj1.get_id() != threadObj2.get_id())
			std::cout << "Both Threads have different IDs" << std::endl;

	std::cout << "Thread 1 ID :: " << threadObj1.get_id() << std::endl;
	std::cout << "Thread 2 ID :: " << threadObj2.get_id() << std::endl;

	threadObj1.join();
	threadObj2.join();

	return 0;
}
