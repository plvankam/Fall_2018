
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include<ctime>
#include<cmath>
#include<functional>

using std::endl;

std::vector<int> GenerateRandVec(int numOfNums, 
                                 int min, 
                                 int max);

int main()
{

    std::function<int(int)> Fib = [&Fib](int n) {return (n < 2) ? n : 
                                         Fib(n - 1) + Fib(n - 2);};
    std::cout << "fib 4 : " << Fib(4) << endl;

    return 0;
}

// generate random number ()
std::vector<int> GenerateRandVec(int numOfNums, 
                                 int min, 
                                 int max)
{
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numOfNums)
    {
        randVal = (min + std::rand()) % ((max + 1) - min);
        vecValues.push_back(randVal);
        ++i;
    }
    return vecValues;
}
