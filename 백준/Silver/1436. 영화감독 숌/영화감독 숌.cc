#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

bool end(string str, int length) {
	int count = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == '6') count++;
		else { count = 0; }
		if (count == 3) return true;
	}
	return false;
}

int main(void) {
	int series;
	int count = 0;
	cin >> series;

	int i = 666;
	while (true) {
		string str = to_string(i);
		if (end(str, str.length())) {
			count++;
		}
		if (count == series) {
			cout << i;
			break;
		}
		i++;
	}
	return 0;
}