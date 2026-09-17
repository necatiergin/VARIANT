#include <string>
#include <variant>
#include <iostream>
#include <bitset>

class Visitor {
public:
	void operator()(const std::string& s, std::bitset<32>bts)
	{
		std::cout << "string : " << s << "\nbitset = " << bts << '\n';
	}

	void operator()(int i, char c)
	{
		std::cout << "int : " << i << "\nchar : " << c << '\n';
	}

	void operator()(double d, std::bitset<32> bts)
	{
		std::cout << "double : " << d << "\nbitset: " << bts << '\n';
	}


	void operator()(const auto&, const auto&)
	{
		std::cout << "other types\n";
	}
};


int main()
{
	std::variant<int, double, std::string> vx{ 12 };
	std::variant<char, long, std::bitset<32>> vy{ 'A' };

	std::visit(Visitor{}, vx, vy);
}
