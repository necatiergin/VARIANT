#include <variant>
#include <string>
#include <iostream>

int main()
{
	using namespace std;

	cout << boolalpha;

	auto f = [](const auto& val) {
		cout << "deger: " << val << '\n';
	};
	
	variant<bool, string> var;
	var = "necati";

	// C++20 oncesi bool ogeye atama yapilmis olurdu
	cout << "index: " << var.index() << '\n';
	visit(f, var);

	var.emplace<1>("ekrem");
	cout << "index: " << var.index() << '\n';
	visit(f, var);

	var.emplace<string>("elif");
	visit(f, var);

	var = "sinan"s;
	visit(f, var);
}
