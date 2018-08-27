#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>

using std::endl;

int main()
{

    // vector of strings 
    std::vector<std::string> nstrVec(10);

    // 
    std::string str("I'm a string");
    // push onto vector 
    nstrVec[0] = str;

    std::cout << str.front() << endl;
    std::cout << str.back() << endl;

    for(auto y: nstrVec)
    {
        std::cout << y << endl;
    }


    return 0;
}

