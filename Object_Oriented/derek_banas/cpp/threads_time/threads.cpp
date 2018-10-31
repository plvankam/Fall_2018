#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<thread>
#include<mutex>


using std::endl;

// RANDOM NUMBER
int GetRandom(int max){
    // using ms
    srand(time(NULL));
    return rand() % max;
}

// GET TIME
std::string GetTime()
{
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = 
        std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&sleepTime);
}

//##############################
// GLOBAL
double acctBalance = 100;

// protects against 
// accessing resources 
// at the same time  
std::mutex acctLock;

//______________________________

void GetMoney(int id, double withdrawal )
{
    // protect balance from being 
    // accessed by more than one thread at a time
    // locks entire scope of function 
    // once other threads try to come in here
    // to execute
    std::lock_guard<std::mutex> lock(acctLock); 
//     not as safe were an exception to 
//     occur ... but worth exploring 
//     acctLock.lock();
//     // ---> code goes here 
//     acctLock.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << id << 
        " tries to withdrawal $" << 
        withdrawal << " on " << 
        GetTime() << endl;
    if((acctBalance - withdrawal) >= 0)
    {
        acctBalance -= withdrawal;
        std::cout << "New Account Balance: " << 
            acctBalance << endl;
    }
    else
    {
        std::cout << "Not enough money in account."     << endl;
        std::cout << "Current Balance: " << acctBalance << endl;
    }
}

void ExecuteThread(int id)
{
    // current time 
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = 
        std::chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);

    std::cout << "Thread " << id << " Sleep Time : " 
              << std::ctime(&sleepTime) << endl;

    std::cout << "Month   : " << myLocalTime.tm_mon          << endl;
    std::cout << "Day     : " << myLocalTime.tm_mday         << endl;
    std::cout << "Year    : " << myLocalTime.tm_year + 1900  << endl;
    std::cout << "Hours   : " << myLocalTime.tm_hour         << endl;
    std::cout << "Seconds : " << myLocalTime.tm_sec          << endl;

    // sleep
    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread " << id << " Awake Time : " 
              << std::ctime(&sleepTime) << endl;

}


int main()
{

    //  SINGLE THREAD
    std::thread th1 (ExecuteThread, 1);
    th1.join();

    // pool of threads 
    std::thread threads[10];
    for(int i; i < 10; ++i)
    {
        // std::thread(funtion, id, args...)
        threads[i] = std::thread(GetMoney, i, 15);
    }
    for(int i; i < 10; ++i)
    {
        threads[i].join();
    }

    return 0;
}
