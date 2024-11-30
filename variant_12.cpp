#include <variant>
#include <string>
#include <iostream>

int main()
{
	boolalpha(std::cout);

	auto f = [](const auto& val) {
		std::cout << "value : " << val << '\n';
		};

	std::variant<bool, std::string> var;
	var = "necati";

	// before C++20 bool alternative is assigned
	std::cout << "index: " << var.index() << '\n';
	visit(f, var);

	var.emplace<1>("ekrem");
	std::cout << "index: " << var.index() << '\n';
	visit(f, var);

	var.emplace<std::string>("elif");
	visit(f, var);

	var = std::string{ "sinan" };
	visit(f, var);
}
