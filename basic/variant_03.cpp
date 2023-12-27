#include <variant>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	variant<int, string> var{ "necati" };
	cout << var.index() << '\n';
	var = 234;
	cout << "index = " << var.index() << '\n';
	try {
		int i = get<0>(var);
		cout << "i = " << i << '\n';
		string str = get<1>(var);
		cout << "str = " << str << '\n';
	}
	catch (const std::bad_variant_access& e) {
		cerr << "exception caught  " << e.what() << '\n';
	}
}
