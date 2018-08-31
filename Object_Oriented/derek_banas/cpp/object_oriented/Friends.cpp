#include<iostream>

using std::endl;

class Customer
{
    private:
        friend class GetCustomerData;
        std::string name;
    public:
        Customer(std::string name) : name(name) {}
};

class GetCustomerData
{
    public:
        static std::string GetName(Customer& customer) 
        {
            return customer.name;
        }
};

int main()
{

    Customer tom("tom");
    GetCustomerData getName;
    std::cout << "Name : " 
              << getName.GetName(tom)
              << endl;

    return 0;
}

