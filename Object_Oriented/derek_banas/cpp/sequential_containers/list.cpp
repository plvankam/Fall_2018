#include<iostream>
#include<deque>
#include<list>

bool isEven(const int& val) {
    return !(val % 2);
}

#define BLANK_LINE std::cout << std::endl;


template<typename T>
void print_list(T list)
{
    for(int i: list) {
        std::cout << i << " ";
    }
    BLANK_LINE
}

template<typename T, typename U>
void insert(T& list, U& array)
{
    list.insert(list.begin(), array, array + sizeof(array)/sizeof(U));
    std::cout << "sizeof(array)/sizeof(U)): " << sizeof(array)/sizeof(U);
    BLANK_LINE
}

int main() 
{

    int arr[5] = {1,2,3,4,5};
    std::list<int> list1;
    // .insert()
    list1.insert(list1.begin(), arr, arr + 5);
    print_list(list1);

    std::list<int>::iterator it2 = list1.begin();
    // access 2nd item in list 
    std::advance(it2 , 2);
    std::list<int>::iterator paper = it2;
    std::cout << "2nd Index: " << *it2   << std::endl;
    std::cout << "paper    : " << *paper << std::endl;

    // insert 
    it2 = list1.begin();
    list1.insert(it2, 8);
    print_list(list1);
    

    int arr1[] = {1,2,3,4,5};
    std::list<int> data_list;
    insert(data_list, arr1);
    print_list(data_list);


    return 0;
}
