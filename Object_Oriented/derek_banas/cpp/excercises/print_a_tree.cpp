#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>

// range()
std::vector<int> Range(int start, int max, int step);
// print_tree()
void print_tree(int);

int main(int argc, char** argv)
{

    int num;
    std::cout << "How tall is your tree? ";
    std::cin >> num;

    print_tree(num);

    return 0;
}

// range()
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

// print_tree()
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
