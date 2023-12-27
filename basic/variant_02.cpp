#include <iostream>
#include <variant>

int main()
{
	using namespace std;

	variant<int, double> v1, v2;
	cout << std::get<int>(v1) << '\n';
	v1 = 12; //v1 holds an int

	int& i = std::get<int>(v1);
	++i;
	cout << get<int>(v1) << '\n';
	get<int>(v1) = 20;
	cout << std::get<int>(v1) << '\n';

	v2 = std::get<int>(v1);
	v2 = std::get<0>(v1); // same as above
	v2 = v1; // same as above

	//auto f = std::get<float>(v1); // error: variant has no float alternative
	//auto x = std::get<3>(v1);      // error: invalid index

	try {
		double dval = get<double>(v2); // current alternative is int not double. throws exception
	}
	catch (const bad_variant_access& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}
