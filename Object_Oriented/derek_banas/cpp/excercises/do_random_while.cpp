#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<ctime>

using std::endl;

// range()
std::vector<int> Range(int start, int max, int step);
// print_tree()
void print_tree(int);

//##############################
//      main()
//##############################
int main(int argc, char** argv)
{

    // seed
    srand(time(NULL));
    // generate number 
    int secretNum = std::rand() % 10 + 1;
    // users guess 
    int guess = 0;

    int repeat = 0;
    do
    {
        std::cout << "Guess the number : ";
        std::cin >> guess;
        if     (guess > secretNum) 
        {
            std::cout << "Too big\n";
            repeat = 1;
        }
        else if(guess < secretNum) 
        {
            std::cout << "Too small\n";
            repeat = 1;
        }
        else 
        {
            repeat = 0;
        }
    }while(repeat);

    std::cout << "CONGRATULATIONS!!  You guessed the right number" << endl;
    
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
