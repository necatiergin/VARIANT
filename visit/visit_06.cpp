#include <variant>
#include <iostream>
#include <string>

struct triple {
	template<typename T>
	void operator()(T& t)const
	{
		t = t + t + t;
	}
};

int main()
{
	using namespace std;

	variant<int, string, double> vx{ 243 };

	visit(triple{}, vx);

	cout << get<0>(vx) << '\n';
	vx = "can";
	visit(triple{}, vx);
	cout << get<1>(vx) << '\n';
	vx = 4.5;
	visit(triple{}, vx);
	cout << get<2>(vx) << '\n';
}
