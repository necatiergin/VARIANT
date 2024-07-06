#include <variant>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	using namespace std;

	using vtype = variant<string, vector<int>, double>;
	
	vtype v1(in_place_index<1>, { 3, 5, 7, 1, 3 });
	vtype v2(in_place_type<vector<int>>, { 3, 5, 7, 1, 3 });
	vtype v3(in_place_index<0>, 20, 'A');
	vtype v4(in_place_type<string>, 20, 'A');

}
