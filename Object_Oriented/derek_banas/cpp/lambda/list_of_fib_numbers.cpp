
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

    std::vector<int> fib_list;
    int list_len;

    // user input 
    std::cout << "How many fibonacci numbers would you like? ";
    std::cin >> list_len;

    // recursive fib lambda function 
    std::function<int(int)> Fib = [&Fib](int n) {return (n < 2) ? n : 
                                         Fib(n - 1) + Fib(n - 2);};
    // loop for filling vector 
    int i = 1;
    while(i <= list_len)
    {
        fib_list.push_back(Fib(i));
        ++i;
    }

    for(std::vector<int>::iterator it = fib_list.begin();
            it != fib_list.end(); ++it)
    {
        std::cout << *it << "\n";
    }

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
