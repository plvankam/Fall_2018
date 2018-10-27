#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using std::endl;
using std::cout;

class Person
{
public:
	std::string m_name;
	int m_id;
	Person(std::string name, int id) : m_name(name), m_id(id) {}
	// use for std::unique()
	bool operator==(const Person& obj);
	// use for std::sort()
	bool operator< (const Person& obj);
};

// operator ==
bool Person::operator==(const Person& obj)
{
	return (m_id == obj.m_id) ? true : false; 
}
// operator < 
bool Person::operator<(const Person& obj)
{
	return (m_id < obj.m_id) ? true : false; 
}

int main()
{

	// ---
	// vector of Ints 
	std::vector<int> vecOfInts = {5,3,1,6,7,6,7,6,9,0,2,3,5};
	// std::sort()
	std::sort(vecOfInts.begin(), vecOfInts.end());
	std::vector<int>::iterator newEnd;
	// overload '==' to change std::unique
	vecOfInts.erase(std::unique(vecOfInts.begin(), vecOfInts.end()), 
					vecOfInts.end());
	cout << "[";
	std::for_each(vecOfInts.begin(), vecOfInts.end(), 
					[](int a){
					static int count = 0;
					if(!count) {std::cout << a; ++count;}
					else       {std::cout << ", " << a; }
					count++;
					});
	cout << "]" << endl;
	// ---

	// ---
	// vecOfPersons: std::sort(), std::unique()
	std::vector<Person> vecOfPersons = {Person("aaa",7), 
										Person("kkk",3),
										Person("aaa",10),
										Person("kkk",7)};
	// uses overloaded '<'
	std::sort(vecOfPersons.begin(),vecOfPersons.end());
	// uses overloaded '=='
	vecOfPersons.erase(std::unique(vecOfPersons.begin(),vecOfPersons.end()),
					  vecOfPersons.end());
	std::for_each(vecOfPersons.begin(), vecOfPersons.end(),
				  [](Person& obj){
				  std::cout << obj.m_id << " :: " << obj.m_name << endl;
				  });
	


	return 0;
}
