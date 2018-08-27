
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

    // sort the vector 
    std::sort(vecVals.begin(), vecVals.end(),
            [](int x, int y){return x > y;});
    std::cout << "\n  * * * * * * * * * * " << endl;

    std::vector<int> evenVals;
    std::copy_if(vecVals.begin(), vecVals.end(),
                 std::back_inserter(evenVals),
                 [](int x){return ((x % 2) == 0);});
    // print unsorted vector 
    for(auto a : evenVals) printf("%3d is an even number \n",a);
    std::cout << "  * * * * * * * * * * " << endl;



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
