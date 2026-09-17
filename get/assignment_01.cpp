#include <iostream>
#include <variant>

int main()
{
	using namespace std;

	variant<int, double> v1, v2;
	cout << get<int>(v1) << '\n';
	v1 = 12; //v1 holds an int

	int& i = get<int>(v1);
	++i;
	cout << get<int>(v1) << '\n';
	get<int>(v1) = 20;
	cout << get<int>(v1) << '\n';

	v2 = get<int>(v1);
	v2 = get<0>(v1); // same as above
	v2 = v1; // same as above

	//auto f = get<float>(v1); // error: variant has no float alternative
	//auto x = get<3>(v1);      // error: invalid index

	try {
		double dval = get<double>(v2); // current alternative is int not double. throws exception
	}
	catch (const bad_variant_access& ex) {
		cout << "exception caught: " << ex.what() << '\n';
	}
}
