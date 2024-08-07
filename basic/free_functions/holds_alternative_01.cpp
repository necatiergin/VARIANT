#include <variant>
#include <string>
#include <iostream>

int main()
{
	using namespace std;

	cout.setf(std::ios::boolalpha);
	variant<int, string> v = "abc";
	cout << "variant holds int     : " << holds_alternative<int>(v) << '\n';
	cout << "variant holds string  : " << holds_alternative<string>(v) << '\n';
	cout << "\n\n";

	v = 23;

	cout << "variant holds int     : " << holds_alternative<int>(v) << '\n';
	cout << "variant holds string  : " << holds_alternative<string>(v) << '\n';
}
