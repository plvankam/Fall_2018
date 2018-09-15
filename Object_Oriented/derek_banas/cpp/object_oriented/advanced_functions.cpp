#include<iostream>
#include<vector>
#include<functional>

using std::endl;

double MultBy2(double num)
{
    return num * 2;
}

double DoMath(std::function<double(double)> func, double num)
{
    return func(num); 
}

double MultBy3(double num)
{
    return num * 3;
}

int main()
{

    auto times2 = MultBy2;
    std::cout << "5 * 2 = " 
              << times2(5) << endl;
    std::cout << "6 * 2 = "
              << DoMath(times2, 6) << endl;

    std::vector<std::function<double(double)>> funcs(2);
    funcs[0] = MultBy2;
    funcs[1] = MultBy3;
    std::cout << "2 * 10 = "
              << funcs[0](10) << endl;


    return 0;
}
