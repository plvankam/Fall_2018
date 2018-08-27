
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

    // generate random vector of in values 
    std::vector<int> vecVals = GenerateRandVec(10,1,50);

    //______________________________
    // print unsorted vector 
    for(auto a : vecVals) std::cout << a << endl;
    //______________________________
    // sort the vector 
    std::sort(vecVals.begin(), vecVals.end(),
            [](int x, int y){return x > y;});
    std::cout << "* * * * * * * * * * " << endl;
    //______________________________
    // print sorted vector 
    for(auto a : vecVals) std::cout << a << endl;


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
