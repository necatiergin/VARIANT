#include <iostream>
#include <variant>

struct A {
	char buf[128];
};

struct B {
	char buf[64];
};


struct C {
	int a[16];
};


int main()
{
	std::variant<A, B, C> x;

	std::cout << sizeof(x) << '\n';
}

