#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>

// range()
std::vector<int> Range(int start, int max, int step);
// print_tree()
void print_tree(int);

//##############################
//      main()
//##############################
int main(int argc, char** argv)
{

    double num1 = 0, num2 = 0;

    int repeat = 0;
    do
    {
        std::cout << "Enter number 1: ";
        std::cin >> num1;
        std::cout << "Enter number 2: ";
        std::cin >> num2;
    try{
        if(num2 == 0)
        {
            throw "Division by zero is not possibl3e";
        }
        else
        {
            printf("%.1f / %.1f = %.2f\n", num1, num2, (num1/num2));
            repeat = 0;
        }
    }
    catch(const char* exp){
        std::cout << "Error : " << exp << "\n";
        repeat = 1;
    }
    }while(repeat);
    
    return 0;
}
//##############################

//------------------------------
// range()
//------------------------------
std::vector<int> Range(int start, int max, int step)
{
    int i = start;
    std::vector<int> range;

    while(i <= max)
    {
        range.push_back(i);
        i += step;
    }
    return range;
}

//------------------------------
// print_tree()
//------------------------------
void print_tree(int height)
{

    // largest row size
    int largest = ((2 * height) - 1); 
    // 
    int trunk_spacing;
    // spacing 
    for (int i = 1; i <= height; ++i)
    {
        int j = 0;
        while(j < (height-i))
        {
            if(!j && (1 == i)) trunk_spacing = (height - i);
            std::cout << " ";
            ++j;
        }
        j = 0;
        while(j < ((2 * i) - 1))
        {
            std::cout << "#";
            ++j;
        }
        std::cout << std::endl;
    }
    for(int j = 0; j < trunk_spacing; ++j) std::cout << " ";
    std::cout << "#" << std::endl;

}
