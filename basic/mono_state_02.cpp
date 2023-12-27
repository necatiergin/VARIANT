#include <variant>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	variant<monostate, string, int, double> vx;

	if (holds_alternative<monostate>(vx))
		cout << "empty (monostate)\n";
	else
		cout << "not empty\n";

	if (get_if<monostate>(&vx))
		cout << "variant bos (monostate)\n";
	else
		cout << "variant bos degil\n";

	if (get_if<0>(&vx))
		cout << "variant bos (monostate)\n";
	else
		cout << "variant bos degil\n";

	if (vx.index() == 0)
		cout << "empty (monostate)\n";
	else
		cout << "not empty\n";

	if (!vx.index())
		cout << "empty (monostate)\n";
	else
		cout << "not empty\n";
}
