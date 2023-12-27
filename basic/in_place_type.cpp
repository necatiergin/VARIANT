#include <variant>
#include <complex>

int main()
{
	using namespace std;
	//variant<complex<double>> v1{ 3.0, 4.0 }; // gecersiz
	//variant<complex<double>> v2{ {3.0, 4.0} }; // ERROR
	variant<complex<double>> v11{in_place_type<complex<double>>, 3.0, 4.0 };
	variant<complex<double>> v12{in_place_index<0>, 3.0, 4.0 };
}
