#include <variant>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	using vtype = variant<int, double, string>;
	vector<vtype> vec{ 199, 3.14159, "necati ergin", "hakan koc" };

	for (const vtype& val : vec) {
		visit([](const auto& v) {
			if constexpr (std::is_same_v<decltype(v),
			const std::string&>) {
				cout << quoted(v) << ' ';
			}
			else {
				cout << v << ' ';
			}
			},
			val);
	}
}
