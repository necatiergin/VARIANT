#include <variant>
#include <iostream>
#include <set>
#include <cmath>

int main()
{
	auto pred = [](int x, int y) {
		return std::abs(x) < std::abs(y);
	};

	std::variant<
		std::set<int>,
		set<int, decltype(pred)>> vx{
		std::in_place_index<1>,
		{4, 8, -7, -2, 0, 5},
		pred };

}
