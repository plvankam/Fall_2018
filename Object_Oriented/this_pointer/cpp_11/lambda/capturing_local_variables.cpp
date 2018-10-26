#include<iostream>
#include<string>

// var0 and var1 are immutable
// ==> [var0, var1]() { func body }
//______________________________
// var0 and var1 are mutable 
// and passed by value 
// ==> [var0, var1]() mutable { func body }
//______________________________
// var0 and var1 are mutable 
// and passed by reference  
// ==> [&var0, &var1]() mutable { func body }
//______________________________
// capture all local variables by reference 
// ==> [&]() { func body }
//______________________________
// capture all local variables by value  
// ==> [=](){ func body }
//


int main(int argc, char* argv[])
{

	std::string msg = "Hello";
	int counter = 10;

	auto func = [&msg, &counter] () {
		std::cout << "Inside Lambda :: msg     =  " << msg << std::endl;	
		std::cout << "Inside Lambda :: counter =  " << counter << std::endl;	
		msg = "Temp";
		counter = 20;
		std::cout << "______________________________" << std::endl;	
		std::cout << std::endl;
		std::cout << "Inside Lambda :: msg     =  " << msg << std::endl;	
		std::cout << "Inside Lambda :: counter =  " << counter << std::endl;	
	};

	func();

	return 0;
}
