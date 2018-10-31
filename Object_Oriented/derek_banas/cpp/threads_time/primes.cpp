#include<iostream>
#include<thread>
#include<string>
#include<ctime>
#include<vector>
#include<mutex>

using std::endl;
using std::cout;
using std::string;

std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start,
        unsigned int end)
{
    for(unsigned int x = start; x <= end; x += 2)
    {
        for(unsigned int y = 2; y < x ; ++y)
        {
            if(!(x % y))
            {
                break;                
            }
            else if ((y + 1) == x)
            {
                // guard 
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(unsigned int start,
        unsigned int end, 
        unsigned int numThreads)
{
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;
    for(unsigned int x = 0; x < numThreads; ++x)
    {
        threadVect.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
    for(auto& t: threadVect)
    {
        t.join();
    }
}

int main()
{

    int startTime = clock();
    FindPrimesWithThreads(1, 1e5, 3);
    int endTime = clock();
    for(auto i: primeVect)
    {
        cout << i << endl;
    }
    std::cout << "Exection Time : " <<
        (endTime - startTime)/double(CLOCKS_PER_SEC) << endl;

    return 0;
}
