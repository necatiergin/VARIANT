#include <variant>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	variant<int, string, double> vx{ "mustafa" };

	cout << get<1>(vx) << '\n';
	auto f = [](auto& val) {
		val = std::remove_reference_t<decltype(val)>{};
	};

	visit(f, vx);
	cout << get<1>(vx).size() << '\n';
	vx = 999;
	cout << get<0>(vx) << '\n';
	visit(f, vx);
	cout << get<0>(vx) << '\n';
	vx = 56.76;
	cout << get<2>(vx) << '\n';
	visit(f, vx);
	cout << get<2>(vx) << '\n';
}
