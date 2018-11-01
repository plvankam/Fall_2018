#include<iostream>
#include<memory>

int main()
{

	// make_shared<>()
	std::shared_ptr<int> p1 = std::make_shared<int>();
	*p1 = 78;
	std::cout << "p1 = " << *p1 << std::endl;

	// show count
	std::cout << "p1 Reference count: " << p1.use_count() << std::endl;

	// make another pointer to int 
	std::shared_ptr<int> p2(p1);

	// shows the reference count 
	std::cout << "p1 Reference count: " << p1.use_count() << std::endl;
	std::cout << "p2 Reference count: " << p2.use_count() << std::endl;

	if(p1 == p1) std::cout << "p1 and p2 are pointing to same pointer\n";
	
	std::cout << "Reset p1" << std::endl;
	// .reset()
	p1.reset();
	std::cout << "p1 Reference Count: " << p1.use_count() << std::endl;
	std::cout << "p2 Reference Count: " << p2.use_count() << std::endl;
	p1.reset(new int(11));
	std::cout << "p1 Reference Count: " << p1.use_count() << std::endl;
	p1 = nullptr;
	if(!p1) std::cout << "p1 is NULL" << std::endl;

	return 0;
}
