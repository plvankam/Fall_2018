#include<iostream>
#include<memory>

struct Sample
{
	Sample()  { std::cout << "CONSTRUCTOR\n";}
	~Sample() { std::cout << "DESTRUCTOR\n";}
};

// template<typename T>
// void deleter(T * x)
void deleter(Sample* x)
{
	std::cout << "DELETER FUNCTION CALLED";
	delete [] x;
}



int main()
{
	std::shared_ptr<Sample> p3(new Sample[12], deleter );
	std::shared_ptr<int>    p4(new int[12], [](int* x){
					std::cout << "deleter function called\n";
					delete [] x;
					});
	return 0;
}
