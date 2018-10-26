#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

class Employee
{
    int m_id;
    std::string m_name;
public:
    Employee(int id, std::string name)
    {
        m_id = id;
        m_name = name;
    }
    void displayEmployeeInfo()
    {
        std::cout<<"Employee ID :: "<<m_id<< "  , Name :: "<<m_name<<std::endl;
    }
};



void getEmployeeList(std::vector<Employee *> & vecOfEmployees)
{
	// create instances of Employee on HEAP
    vecOfEmployees.push_back(new Employee(1, "Varun"));
    vecOfEmployees.push_back(new Employee(1, "John"));
    vecOfEmployees.push_back(new Employee(1, "Ritu"));
    vecOfEmployees.push_back(new Employee(1, "Jack"));
}


int main()
{

	std::vector<Employee*> vecOfEmployees;
	getEmployeeList(vecOfEmployees);
	std::for_each(vecOfEmployees.begin(),vecOfEmployees.end(), 
				  std::bind(std::mem_fun(&Employee::displayEmployeeInfo),
				  std::placeholders::_1));
	// delete each instance of Employee
	std::for_each(vecOfEmployees.begin(), vecOfEmployees.end(),
				  [](Employee* emp){
				  delete emp;
				  });

	return 0;
}
