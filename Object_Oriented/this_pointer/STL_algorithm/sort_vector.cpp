#include<iostream>
#include<vector>
#include<algorithm>

class Person {
public:
    std::string m_name;
    int m_id;
    Person(std::string name, int id) : m_name(name), m_id(id) {}

	// --
	// std::sort uses '<' to sort 
    bool operator <(const Person& obj) { return (m_id < obj.m_id) ?  true : false; }
	// --
};

int main()
{
	std::vector<std::string> vecOfStrings;
 
	vecOfStrings.push_back("bbb");
	vecOfStrings.push_back("fff");
	vecOfStrings.push_back("aaa");
	vecOfStrings.push_back("ccc");
	vecOfStrings.push_back("abc");
 
	std::sort(vecOfStrings.begin(), vecOfStrings.end());
 
	int counter = 0;
	// --
	std::for_each(vecOfStrings.begin(), vecOfStrings.end(),
			[counter](std::string str) {
				 std::cout<<str<< " " << counter;
			});
	// --

	// 
    std::vector<Person> vecOfPersons = { Person("aaa", 7), Person("kkk", 3),
    Person("ddd", 5), Person("abc", 2) };
     
    std::sort(vecOfPersons.begin(), vecOfPersons.end());
     
    std::cout << "Sorted Persons List based on ID\n";
    std::for_each(vecOfPersons.begin(), vecOfPersons.end(), [](Person & obj) {
    std::cout<<obj.m_id<< " :: "<<obj.m_name<<std::endl;
    });

	return 0;
}
