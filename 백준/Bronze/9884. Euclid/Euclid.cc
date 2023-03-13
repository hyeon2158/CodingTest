#include <iostream>

using namespace std;

int divi(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return divi(b, a % b);
}

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << divi(a, b);
	return 0;
}