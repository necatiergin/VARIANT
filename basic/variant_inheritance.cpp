#include <variant>
#include <string>
#include <iostream>

class Derived : public std::variant<int, std::string> {};


int main()
{
	using namespace std;

	Derived d = { "hello" };
	cout << d.index() << '\n';
	cout << get<1>(d) << '\n';
	d.emplace<0>(77);
	cout << get<0>(d) << '\n';
}
