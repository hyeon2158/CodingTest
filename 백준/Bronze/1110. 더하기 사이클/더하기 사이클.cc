#include <iostream>

using namespace std;

int decode(int a) {
	int b;
	b = a % 10 * 10 + (a / 10 + a % 10) % 10;
	return b;
}
int main() {
	int a;
	int b;
	int count = 0;
	cin >> a;
	
	b = decode(a);
	count++;

	while (a != b) {
		b = decode(b);
		count++;
	}
	cout << count;
}