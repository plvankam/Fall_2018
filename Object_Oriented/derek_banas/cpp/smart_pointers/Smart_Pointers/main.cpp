#include <QCoreApplication>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <memory>
#include <iostream>
#include <memory>

using std::endl;
using std::cout;

// --
// class Pizza{}
class Pizza{
public:
    virtual void MakePizza() = 0;
};

// --
// class NYStyleCrust{}
class NYStyleCrust{
public:
    std::string AddIngredient() {return "Crust so thi you can see through it\n\n";}
};
// --
// class DeepDishCrust{}
class DeepDishCrust{
public:
    std::string AddIngredient() {return "Super awesome Chicago Deep Dish\n\n";}
};

template<typename T>
class LotsOfMeat: public T{
public:
    std::string AddIngredient()
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int amtToStore;
    std::cout << "How many numbers do you want to store: ";
    std::cin >> amtToStore;
    // --
    // MALLOC
    // --
    int* pNums = (int*)malloc(amtToStore * sizeof(int)); // --> malloc pNums
    if(pNums != NULL)
    {
        int i = 0;
        while(i < amtToStore)
        {
            std::cout << "Enter a Number: ";
            std::cin  >>  pNums[i];
            ++i;
        }
        std::cout << "You entered: [";
        i = 0;
        while(i < amtToStore)
        {
            cout << pNums[i];
            if((i +1) == amtToStore) std::cout << "]" << endl;
            else                     std::cout << ", ";
            ++i;
        }
    } // endif
    delete pNums; // delete pNums
    // --
    // SMART POINTER
    // --
    // NOTE: unique_ptr<> cannot be shared
    //
    std::cout << "How many numbers do you want to store: ";
    std::cin >> amtToStore;
    std::unique_ptr<int[]> pNums1(new int[amtToStore]);
    int i = 0;
    while(i < amtToStore)
    {
        std::cout << "Enter a Number: ";
        std::cin  >>  pNums1[i];
        ++i;
    }
    std::cout << "You entered: [";
    i = 0;
    while(i < amtToStore)
    {
        cout << pNums1[i];
        if((i +1) == amtToStore) std::cout << "]" << endl;
        else                     std::cout << ", ";
        ++i;
    }


    return a.exec();
}

