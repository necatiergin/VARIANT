#include <string>
#include <iostream>
#include <variant>

struct PrintVisitor{

	void operator()(const auto& val) const
	{
		std::cout << "value is : " << val << '\n';
	}
};

int main()
{
	using namespace std;

	variant<int, double, string> ids;
	static_assert(variant_size_v<decltype(ids)> == 3);
	visit(PrintVisitor{}, ids);

	cout << "index = " << ids.index() << '\n';
	
	ids = 45.678;
	
	cout << "index = " << ids.index() << endl;
	
	ids = "Necati Ergin";
	
	cout << "index = " << ids.index() << endl;

	if (const auto iptr = get_if<int>(&ids))
		cout << "int: " << *iptr << '\n';
	else if (const auto dptr = get_if<double>(&ids))
		cout << "double: " << *dptr << '\n';

	if (holds_alternative<int>(ids))
		cout << "the variant holds an int!\n";
	else if (holds_alternative<double>(ids))
		cout << "the variant holds a float\n";
	else if (holds_alternative<string>(ids))
		cout << "the variant holds a string\n";
	
	try {
		auto dval = get<double>(ids);
		cout << "double " << dval << '\n';
	}
	catch (const bad_variant_access& ex)
	{
		cout << ex.what() << '\n';
	}
}
