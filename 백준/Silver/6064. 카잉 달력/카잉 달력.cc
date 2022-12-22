#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int a = 0;
		int b = 0;
		int c = lcm(M, N);
		for (size_t i = x; i <= c; i+=M)
		{
			a = (i - 1) % M + 1;
			b = (i - 1) % N + 1;
			if (a == x && b == y) {
				cout << i << '\n';
				break;
			}
			else if (i+M > c) cout << "-1\n";
		}
	}

	return 0;
}