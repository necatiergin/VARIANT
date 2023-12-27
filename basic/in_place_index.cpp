#include <variant>
#include <iostream>
#include <set>

int main()
{
	using namespace std;

	auto pred = [](int x, int y) {
		return abs(x) < abs(y);
	};

	std::variant<
		set<int>,
		set<int, decltype(pred)>> vx{
		std::in_place_index<1>,
		{4, 8, -7, -2, 0, 5},
		pred };

}
