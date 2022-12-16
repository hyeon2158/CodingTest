#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

bool decode(int const Num) {
	string Str = to_string(Num);
	string Str_Cpy = Str;
	reverse(Str_Cpy.begin(), Str_Cpy.end());
	return Str == Str_Cpy;
}

int main(void) {
	int x;
	cin >> x;
	while(x) {
		if (decode(x)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		cin >> x;
	}
	return 0;
}