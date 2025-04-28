#include <variant>
#include <tuple>
#include <type_traits>
#include <utility>

// Typelist helper
template<typename... Ts>
struct type_list {};

// Prepend a type to a typelist
template<typename T, typename List>
struct prepend;

template<typename T, typename... Ts>
struct prepend<T, type_list<Ts...>> {
    using type = type_list<T, Ts...>;
};

// Find the type with the minimum size
template<typename List>
struct find_min_size_type;

template<typename T>
struct find_min_size_type<type_list<T>> {
    using type = T;
};

template<typename T1, typename T2, typename... Ts>
struct find_min_size_type<type_list<T1, T2, Ts...>> {
private:
    using min_rest = typename find_min_size_type<type_list<T2, Ts...>>::type;
public:
    using type = std::conditional_t<(sizeof(T1) <= sizeof(min_rest)), T1, min_rest>;
};

// Remove a type from a typelist
template<typename RemoveT, typename List>
struct remove_type;

template<typename RemoveT>
struct remove_type<RemoveT, type_list<>> {
    using type = type_list<>;
};

template<typename RemoveT, typename T, typename... Ts>
struct remove_type<RemoveT, type_list<T, Ts...>> {
private:
    using tail_result = typename remove_type<RemoveT, type_list<Ts...>>::type;
public:
    using type = std::conditional_t<
        std::is_same_v<RemoveT, T>,
        tail_result,
        typename prepend<T, tail_result>::type
    >;
};

// Sort a typelist by size
template<typename List>
struct sort_by_size;

template<>
struct sort_by_size<type_list<>> {
    using type = type_list<>;
};

template<typename... Ts>
struct sort_by_size<type_list<Ts...>> {
private:
    using min_type = typename find_min_size_type<type_list<Ts...>>::type;
    using rest = typename remove_type<min_type, type_list<Ts...>>::type;
public:
    using type = typename prepend<min_type, typename sort_by_size<rest>::type>::type;
};

// Create a variant from a typelist
template<typename List>
struct variant_from_type_list;

template<typename... Ts>
struct variant_from_type_list<type_list<Ts...>> {
    using type = std::variant<Ts...>;
};

// User-friendly interface: variant_sorted_by_size<Ts...>
template<typename... Ts>
using variant_sorted_by_size = typename variant_from_type_list<typename sort_by_size<type_list<Ts...>>::type>::type;

// ------------------------
// Test code

#include <iostream>
#include <string>

int main() 
{
    using my_variant = variant_sorted_by_size<std::string, char, int, double>;

    // Expected order: char, int, double, std::string
    std::cout << "sizeof(my_variant) = " << sizeof(my_variant) << "\n";

    my_variant v = 'X';

    std::visit([](auto&& val) {
        std::cout << val << '\n';
        }, v);

    v = 3.1415;

    std::visit([](auto&& val) {
        std::cout << val << '\n';
        }, v);
}
