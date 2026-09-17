#include <iostream>
#include <variant>

int main()
{
	using vtype = std::variant <char, double, int>;

	constexpr auto sz1 = std::variant_size<vtype>::value;
	constexpr auto sz2 = std::variant_size_v<vtype>;
}
