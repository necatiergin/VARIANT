// member function index 

#include <variant>
#include <string>
#include <iostream>

int main()
{
	using namespace std::literals;

	std::variant<int, std::string, double> var;  //default constructed, holds int, index = 0;
	std::cout << "index = " << var.index() << '\n';
	var = "neco"s;
	std::cout << "index = " << var.index() << '\n';
	var = 2.3;
	std::cout << "index = " << var.index() << '\n';
}
