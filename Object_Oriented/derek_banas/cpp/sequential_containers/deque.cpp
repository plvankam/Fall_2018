#include<iostream>
#include<deque>
#include<list>
#include<forward_list>


#define NEW_LINE std::cout << std::endl;

bool isEven(const int& val) { return ((val % 2) == 0); }


int main(int argc, char** argv)
{

    std::deque<int> deq1;
    // .push_back()
    deq1.push_back(5);
    // .push_front()
    deq1.push_front(1);
    std::cout << "deq1.push_back(5); \n" 
              << "deq1.push_front(1);\n"; 
    // for ( : )
    for(int i : deq1) {
        std::cout << i << " "; 
    }
    NEW_LINE 
    // .assign()
    deq1.assign({11,12});
    std::cout << "deq1.assign({11,12});   ";
    for(int i : deq1) {
        std::cout << i << " "; 
    }
    NEW_LINE 
    // .insert()
    int tempArr[5] = {1,2,3,4,5};
    deq1.insert(deq1.end(), tempArr, tempArr+5);
    deq1.insert(deq1.end(), tempArr, tempArr + 1);
    for(int i : deq1) {
        std::cout << i << " "; 
    }
    NEW_LINE 

    // .erase()
    deq1.erase(deq1.end());
    deq1.erase(deq1.begin(), deq1.begin() + 2);
    deq1.pop_front();
    deq1.pop_back();
    for(int i : deq1) {
        std::cout << i << " "; 
    }
    NEW_LINE 


    deq1.pop_front();
    deq1.pop_back();
    for(int i : deq1) {
        std::cout << i << " "; 
    }
    NEW_LINE 
    
    std::deque<int> deq2(2,50);
    std::cout << "deq1 ==> " << std::endl;
    for(int i : deq1) {
        std::cout << i << " "; 
    }
    deq1.swap(deq2);
    std::cout << "std::deque<int> deq2(2,50)" << std::endl
              << "deq1.swap(deq2)" << std::endl;
    for(int i  : deq1) {
        std::cout << i << " ";
    }
    NEW_LINE 



    return 0;
}
