#include<iostream>
#include<iterator>
#include "inc/Animal.h"
#include<vector>

using std::cout;
using std::endl;

#define PI 3.14159
#define AREA_CIRCLE(radius) (PI * radius * radius)

template<typename T>
void Times2(T val)
{
    std::cout << val << " * 2 = "
              << val * 2 << endl;
}
template<typename T>
T Add(T val, T val2)
{
    return val + val2;
}
template<typename T>
T  Max(T val, T val2)
{
    return (val > val2) ? val : val2;
}
template<typename T, typename U>
class Person
{
public:
    T height;
    U weight;
    static int numOfPeople;
    Person(T h, U w) : height(h), weight(w) { numOfPeople++;}
    void GetData()
    {
        std::cout << "Height: " << height
                  << "\nWeight: " << weight
                  << "\nNumber of People: " << numOfPeople
                  << endl;
    }
};

template<typename T, typename U> int Person<T,U>::numOfPeople;

int main()
{

  // animal class
  Animal spot = Animal();
  spot.name = "Spot";
  // defines
  cout << AREA_CIRCLE(4) << endl;
  cout << "The Animal is named "
       <<  spot.name << endl;

  // templating
  Times2(5);
  Times2(4.3);
  std::cout << Max(2.3, 3.4) << endl;
  std::cout << Add(9.3, (double)4) << endl;

  // template class
  Person<double, int> mikeTyson(5.83, 216);
  mikeTyson.GetData();
  std::cout << "Number of People: " << mikeTyson.numOfPeople << endl;

  // iterators
  std::vector<int> nums2 = {1,2,3,4};
  std::vector<int>::iterator itr;
  std::cout << "{";
  // printing an array
  int count = 0;
  for(itr = nums2.begin(); itr < nums2.end();itr++)
  {
    ++count;
    std::cout << *itr ;
    if(nums2.size() != count) std::cout << ", ";
    else                      std::cout << "}\n";
  }
  std::vector<int>::iterator itr2 = nums2.begin();
  // advance()
  advance(itr2, 2);
  std::cout << *itr2 << endl;
  // next()
  auto itr3 = next(itr2,1);
  std::cout << *itr3 << endl;
  // prev()
  auto itr4 = prev(itr2, 1);
  std::cout << *itr4 << endl;
  //

  std::vector<int> nums3 = {1,4,5,6};
  std::vector<int> nums4 = {2,3};
  auto itr5 = nums3.begin();
  advance(itr5,1);
  // copy()
  copy(nums4.begin(), nums4.end(), inserter(nums3, itr5));
  for(int &i: nums3)
  {
    std::cout << i << endl;
  }



  return 0;
}
