#include <variant>
#include <vector>
#include <iostream>

template<typename ... Args>                                                 
struct Overload : Args ... 
{
    using Args::operator() ...;
};

template<class... Args>
Overload(Args...)->Overload<Args...>;

struct Nec {};
struct Erg {};

int main() 
{
    using var_type = std::variant<int, char, unsigned, float, double, long long, Nec, Erg>;

    auto stypes = Overload{                                     
        [](int) { return "int"; },
        [](char) { return "char"; },
        [](unsigned) { return "unsigned"; },
        [](float) { return "float"; },
        [](double) { return "double"; },
        [](long long) { return "long long"; },
        [](Nec) { return "Nec"; },
        [](auto) { return "unknown type"; },
    };

    std::vector<var_type> varvec{ 23, 'A', 45U, 5.f, 6.4, 34LL, Nec{}, Erg{} };
    
    for (auto v : varvec)  {                                           
        std::cout << std::visit(stypes, v) << '\n';
    }
}
