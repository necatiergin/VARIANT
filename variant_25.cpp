#include <string>
#include <iostream>
#include <variant>
#include <list>
#include <algorithm>

class Cat {
public:
	Cat(std::string name) : m_name{ std::move(name) } {}
	void meow() const
	{
		std::cout << m_name << " miyavliyor!\n";
	}
private:
	std::string m_name;
};

////////////////////////////////////////////////////////////////////////////////

class Dog {
public:
	Dog(const std::string name) : m_name{ std::move(name) } {}
	void woof() const
	{
		std::cout << m_name << " havliyor!\n";
	}
private:
	std::string m_name;
};

////////////////////////////////////////////////////////////////////////////////

class Lamb {
public:
	Lamb(const std::string name) : m_name{ std::move(name) } {}
	void bleat() const
	{
		std::cout << m_name << " meliyor!\n";
	}
private:
	std::string m_name;
};

////////////////////////////////////////////////////////////////////////////////

using Animal = std::variant<Dog, Cat, Lamb>;

template <typename T>
bool is_type(const Animal& a)
{
	return std::holds_alternative<T>(a);
}

struct AnimalVoice
{
	void operator()(const Dog& dog) const { dog.woof(); }
	void operator()(const Cat& cat) const { cat.meow(); }
	void operator()(const Lamb& lamb) const { lamb.bleat(); }
};


int main()
{
	using namespace std;
	list<Animal> animal_farm{ Cat{"pamuk"}, Dog{"kont"}, Lamb{"kuzucuk"}, Lamb{"pamuk"}, Cat{"kara"} };

	for (const Animal& a : animal_farm) {
		switch (a.index()) {
		case 0:
			get<Dog>(a).woof();
			break;
		case 1:
			get<Cat>(a).meow();
			break;
		case 2:
			get<Lamb>(a).bleat();
			break;
		}
	}
	cout << "-----------------\n";

	for (const Animal& a : animal_farm) {
		if (const auto dog_ptr = get_if<Dog>(&a)) {
			dog_ptr->woof();
		}
		else if (const auto cat_ptr = get_if<Cat>(&a)) {
			cat_ptr->meow();
		}
		else if (const auto lamb_ptr = get_if<Lamb>(&a)) {
			lamb_ptr->bleat();
		}
	}
	cout << "-----------------\n";

	for (const Animal& a : animal_farm) {
		visit(AnimalVoice{}, a);
	}
	cout << "-----------------\n";

	cout << "hayvan ciftliginde "
		<< count_if(begin(animal_farm), end(animal_farm), is_type<Cat>)
		<< " kedi, "
		<< count_if(begin(animal_farm), end(animal_farm), is_type<Dog>)
		<< " kopek ve "
		<< count_if(begin(animal_farm), end(animal_farm), is_type<Lamb>)
		<< " kuzu yasiyor";
}
