#include <variant>
#include <iostream>
#include <string>

int main()
{
    std::variant<char, int, double ,std::string> var = 'a';

    const auto f{ [](auto x) { std::cout << x << '\n'; } }; //visitor

    std::visit(f, var);
    var = 123;
    std::visit(f, var);
    var = 4.7;
    std::visit(f, var);
    var = "necati";
    std::visit(f, var);
}
