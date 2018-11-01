#include <functional>
#include <iostream>
 
struct Foo {
    void display_greeting() {
        std::cout << "Hello, world.\n";
    }
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data = 7;
};
 
int main() 
{

	Foo f;
	auto greet = std::mem_fn(&Foo::display_greeting);
	auto print_number = std::mem_fn(&Foo::display_number);
	greet(f);
	f.greet();
	print_number(f,42);
	f.display_number(42);

	return 0;
}

