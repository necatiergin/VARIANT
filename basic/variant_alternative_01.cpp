#include <variant>
#include <iostream>

int main()
{
	using vtype = std::variant<int, double, char>;

	std::variant_alternative<2, vtype>::type c{}; //char c
	std::variant_alternative_t<1, vtype> d{}; //double d
	std::variant_alternative_t<0, vtype> i{}; //int i
}
