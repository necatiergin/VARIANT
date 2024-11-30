#include <variant>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	variant<monostate, int, string> v1,
		v2{ "necati" }, v3{ 54 };
	variant<monostate, string, int> v4;
	//v1 == v4 gecersiz
	cout << boolalpha;
	cout << "v1 == v2 : " << (v1 == v2) << '\n';
	cout << "v1 <  v2 : " << (v1 < v2) << '\n';
	cout << "v2 <  v3 : " << (v2 < v3) << '\n';
	v1 = "necati";
	cout << "v1 == v2 : " << (v1 == v2) << '\n';
	v2 = 52;
	cout << "v2 <  v3 : " << (v2 < v3) << '\n';
}
