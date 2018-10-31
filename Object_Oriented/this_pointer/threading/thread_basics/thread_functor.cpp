#include<iostream>
#include<thread>

// CREATE 
// std::thread thObj(<CALLBACK>)
//
//

void thread_function() 
{
    for(int i = 0; i < 100; ++i) {
        std::cout << "thread function Executing" << std::endl;
    }
}

int main()
{

    // create thread with thread function 
    // as callback
    std::thread threadObj(thread_function);
    for(int i = 0; i < 100; ++i) {
        std::cout << "in main()\n";
    }
    // .join()
    threadObj.join();

    return 0;
}
