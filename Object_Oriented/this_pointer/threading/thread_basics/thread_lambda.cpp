#include<iostream>
#include<thread>


int main()
{

    std::thread threadObj([]{
            for(int i = 0; i < 10; ++i){
                std::cout << "Display thread executing" << std::endl;
            }
            });

    for(int i = 0; i < 10; ++i){
        std::cout << "Display from main()" << std::endl;
    }
    threadObj.join();
    std::cout << "Exiting main()" << std::endl;

    return 0;
}
