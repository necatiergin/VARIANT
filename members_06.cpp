#include <string>
#include <variant>
#include <iostream>

int main()
{
	using std::cout;

	try
	{
		using age_t = int;
		using weight_t = double;
		using name_t = std::string;

		std::variant<age_t, weight_t, name_t> va;

		enum : size_t { idx_age, idx_weight, idx_name };

		va = 19;

		cout << "age     = " << get<age_t>(va) << '\n';
		cout << "age     = " << get<idx_age>(va) << '\n';

		va = 83.14;

		cout << "weight  = " << std::get<idx_weight>(va) << '\n';
		cout << "weight  = " << std::get<weight_t>(va) << '\n';

		va = "Necati Ergin";

		cout << "name    = " << get<idx_name>(va) << '\n';
		cout << "name    = " << get<name_t>(va) << '\n';
	}
	catch (const std::bad_variant_access& e)
	{
		cout << "exception caught : " << e.what() << '\n';
	}
}
