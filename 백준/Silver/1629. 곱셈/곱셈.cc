#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef unsigned long long u;

u temp = 0;

u power(u a, u b, u c) {
	if (b == 0) return 1;
	if (b == 1) return a % c;

	temp = power(a, b/2, c) % c;
	if (b % 2 == 0) return (temp * temp) % c;
	return temp * temp % c * a % c;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	u a, b, c;
	cin >> a >> b >> c;
	cout << power(a,b,c);
	return 0;
}