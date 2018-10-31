#include<iostream>
#include<thread>

class DisplayThread
{
    public:
        void operator()()
        {
            for(int i = 0; i < 100; ++i) {
                std::cout << "Display thread executing\n";
            }
        }
};


int main()
{

    std::thread threadObj((DisplayThread()));
    for(int i = 0; i < 100; ++i){
        std::cout << "Display Main Thread" << std::endl;
    }
    std::cout << "Waiting for thread to complete" << std::endl;
    threadObj.join();
    std::cout << "Exiting main()\n";

    return 0;
}
