#include <iostream>
#include <variant>

class A {
public:
	A()
	{
		std::cout << "A()\n";
	}

	A(const A& other) : mx{other.mx}
	{
		std::cout << "A copy ctor\n";
	}

	A(int val) : mx{ val }
	{
		std::cout << "A(int)\n";
	}

	~A()
	{
		std::cout << "~A()\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const A& a)
	{
		return os << "(A : " << a.mx << ")";
	}
private:
	int mx{};
};


class B {
public:
	B()
	{
		std::cout << "B()\n";
	}

	B(const B& other) : mx{ other.mx }
	{
		std::cout << "B copy ctor\n";
	}

	B(int val) : mx{ val }
	{
		std::cout << "B(int)\n";
	}

	~B()
	{
		std::cout << "~B()\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const B& b)
	{
		return os << "(B: " << b.mx << ")";
	}
private:
	int mx{};
};

A ax(10);
B bx(10);


int main()
{
	using namespace std;

	cout << "main started running\n";
	cout.setf(ios::boolalpha);
	variant<A, B> var_ab(ax);

	cout << "get<0>(var_ab) = " << get<0>(var_ab) << '\n';
	cout << "variant holds an A object: " << holds_alternative<A>(var_ab) << '\n';
	cout << "variant holds a  B object: " << holds_alternative<B>(var_ab) << '\n';

	cout << "index value is: " << var_ab.index() << '\n';
	var_ab = bx;

	cout << "variant holds an A object: " << holds_alternative<A>(var_ab) << '\n';
	cout << "variant holds a  B object: " << holds_alternative<B>(var_ab) << '\n';

	cout << "index value is: " << var_ab.index() << '\n';
}
