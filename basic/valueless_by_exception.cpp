#include <variant>
#include <stdexcept>
#include <iostream>


struct S {
	operator int() {
		throw std::runtime_error{ "hata" };
		return 1;
	} // any conversion to int throws
};

int main()
{
	using namespace std;

	variant<double, int> var{ 12.2 }; 
	try {
		var.emplace<1>(S{});
	}
	catch (const std::exception& ex) {
		cout << "hata yakalandi ... " << ex.what() << "\n";
		cout << boolalpha << var.valueless_by_exception() << "\n";
		cout << "var.index() = " << var.index() << "\n";
		std::cout << (var.index() == variant_npos) << "\n";
	}
}
