#include <variant>
#include <vector>
#include <string>
#include <iostream>

int main() 
{
    std::vector<std::variant<char, int, double, std::string>> data = {
        'Y', 42, 3.14, "necati", 7, "ergin", 'X'
    };

    for (const auto& item : data) {
        std::visit([](auto&& val) {
            std::cout << val << "\n";
            }, item);
    }
}
