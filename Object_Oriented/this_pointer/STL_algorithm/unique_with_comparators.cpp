#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using std::endl;
using std::cout;

// ---
// Person 
// ---
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

// ---
// PersonEqualityComparator
// std::unique() overload
// ---
struct PersonEqualityComparator
{
    bool operator()(const Person& first,
    				const Person& last)
    { return (first.m_name == last.m_name) ? true : false; }
};
// ---
// PersonComparator
// std::sort() overload
// ---
struct PersonComparator
{
    bool operator()(const Person& first,
    				const Person& last)
    { return (first.m_name  < last.m_name) ? true : false; }
};


int main()
{


	// ---
	std::vector<Person> vecOfPersons = {Person("aaa",7), 
										Person("kkk",3),
										Person("aaa",10),
										Person("kkk",7)};
	std::sort(vecOfPersons.begin(),vecOfPersons.end(),PersonComparator());
	vecOfPersons.erase(std::unique(vecOfPersons.begin(),vecOfPersons.end(),PersonEqualityComparator()),
					  vecOfPersons.end());
	std::for_each(vecOfPersons.begin(),vecOfPersons.end(),
				  [](const Person& obj) 
				  {
				  cout << obj.m_name << endl;
				  });


	return 0;
}
