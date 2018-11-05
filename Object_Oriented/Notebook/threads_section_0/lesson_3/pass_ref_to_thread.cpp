#include<iostream>
#include<thread>

namespace thread_vars
{
	std::thread::id id;	
}

void threadCallback(int const& x)
{
	thread_vars::id = std::this_thread::get_id();
	int& y = const_cast<int&>(x);
	++y;
	std::cout << "Inside Thread x = " << x << std::endl;
	std::cout << "Thread # :        " << thread_vars::id << std::endl;
}

int main()
{

	int x = 9; 
	std::cout << "Main Thread Before Start x" << std::endl;
	std::thread th(threadCallback, x);
	if(th.joinable()) th.join();

	return 0;

}
