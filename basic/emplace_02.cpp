#include <iostream>
#include <string>
#include <variant>

int main()
{
	using namespace std;

	variant<string, int> v1;

	v1.emplace<0>("necati"); // OK
	cout << get<0>(v1) << '\n';
	v1.emplace<string>("velican"); // OK
	cout << get<0>(v1) << '\n';

	variant<string, string> v2;
	v2.emplace<1>("ghi"); // OK
	cout << get<1>(v2) << '\n';
	//v2.emplace<string>("abc"); //gecersiz
}
