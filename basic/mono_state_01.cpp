// std::monostate

#include <variant>
#include <iostream>

class Data {
public:
	Data(int x) : mx{ x } {}
private:
	int mx;
};

int main()
{
	using namespace std;

	//variant<Data, int, double> v1;  //error: class Data has no default ctor.
	variant<monostate, Data, int, double> v2; //valid

	cout << "index = " << v2.index() << '\n';  // 0

	if (holds_alternative<std::monostate>(v2))
		cout << "empty (monostate)\n";
	else
		cout << "not empty\n";

	if (get_if<std::monostate>(&v2))
		cout << "empty (monostate)\n";
	else
		std::cout << "not empty\n";

	v2 = Data{ 13 };
	cout << "index = " << v2.index() << '\n';
	v2 = 23;
	cout << "index = " << v2.index() << '\n';
	v2 = 4.5;
	cout << "index = " << v2.index() << '\n';
	v2 = std::monostate{};
	cout << "index = " << v2.index() << '\n';
	v2 = {};
	cout << "index = " << v2.index() << '\n';
}
