#include <variant>
#include <iostream>
#include <string>

int main()
{
	using std::variant, std::string, std::cout;

	variant<int, string> v1{ "necati ergin" };
	cout << "v1.index() = " << v1.index() << '\n';
	cout << get<1>(v1).size() << '\n';
	auto v2 = move(v1);
	cout << "v1.index() = " << v1.index() << '\n';
	cout << get<1>(v1).size() << '\n';
	cout << get<1>(v2).size() << '\n';
}
