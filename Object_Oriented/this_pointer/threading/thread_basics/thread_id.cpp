#include<iostream>
#include<thread>

void thread_function()
{
    std::cout << "We are in thread : " << std::this_thread::get_id() << std::endl;
}

int main()
{

    // create threads 
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);
    // check that ids are not the same 
    if(threadObj1.get_id() != threadObj2.get_id())
        { std::cout << "Both threads have different ids" << std::endl;}
    // print ids 
    std::cout << "Thread 1 id: " << threadObj1.get_id() << std::endl;
    std::cout << "Thread 2 id: " << threadObj2.get_id() << std::endl;
    // join()
    threadObj1.join(); threadObj2.join();


    return 0;
}
