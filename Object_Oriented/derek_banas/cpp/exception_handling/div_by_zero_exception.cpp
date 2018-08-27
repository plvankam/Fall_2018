
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include<ctime>
#include<cmath>

using std::endl;

std::vector<int> GenerateRandVec(int numOfNums, 
                                 int min, 
                                 int max);

int main()
{

    // holds number to divide by
    int divisor;
    // vector of 10 random ints
    std::vector<int> vecVals = GenerateRandVec(10,1,50);

    // get user input for divisor
    std::cout << "Enter a number: ";
    try{
        std::cin >> divisor;
        // if it is not numberic
        // else, it will truncate
        if(std::cin.fail())
        {
            throw "This is not right";
        }
        std::cout << " you entered " << divisor << endl;
    }
    catch(const char*  ex) {
        std::cout << ex << endl;
    }

    // print vector
    std::cout << "[";
    for(auto a: vecVals) 
    {
        std::cout << a;
        std::cout << " ";
    }
    std::cout << "]" << endl;


    // find elems divisible by @divisor
    std::vector<int> divByVector;
    std::copy_if(vecVals.begin(), vecVals.end(),
                 std::back_inserter(divByVector),
                 [&](int x){return ((x % divisor) == 0);});
    // print vector 
    for(auto a : divByVector) printf("%3d is an divisible by %3d\n",a,divisor);




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
