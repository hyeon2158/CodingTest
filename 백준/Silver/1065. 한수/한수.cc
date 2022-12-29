#include <iostream>

using namespace std;

int decode(int a) {
	int b = a / 1000;
	int c = a / 100 % 10;
	int d = a / 10 % 10;
	int e = a % 10;
	
	if (b != 0) { return 0; }
	else if (c != 0) {
		if (c - d == d - e) { return 1; }
		else { return 0; }
	}
	else { return 1; }
}
int main() {
	int a;
	int b;
	int count = 0;
	cin >> a;
	
	for (size_t i = 1;  i<= a; i++)
	{
		if (decode(i)) {
			count++;
		}
	}
	cout << count;
}
