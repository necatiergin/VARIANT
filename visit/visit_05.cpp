#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <type_traits>
#include <iomanip>

int main()
{
	using namespace std;

	using vtype = variant<int, double, string>;
	vector<vtype> vec{ 199, 3.14159, "necati ergin", "hakan koc"};

	for (const vtype& val : vec) {
		std::visit([](const auto& v) {
			if constexpr (std::is_same_v<decltype(v),
				const std::string&>) {
				std::cout << quoted(v) << ' ';
			}
			else {
				std::cout << v << ' ';
			}
			},
			val);
	}
}
