#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long u;
int main() {
	u n, m;
	cin >> n >> m;
	vector <vector<u> > DP1(101, vector<u>(101));
	vector <vector<u> > DP2(101, vector<u>(101));
	DP1[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		DP1[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			DP1[i][j] = DP1[i - 1][j] + DP1[i - 1][j - 1];
			DP2[i][j] = DP2[i - 1][j] + DP2[i - 1][j - 1];

			DP2[i][j] += DP1[i][j] / 1'000'000'000'000'000;
			DP1[i][j] %= 1'000'000'000'000'000;
		}
	}

	if (DP2[n][m] == 0) {
		cout << DP1[n][m] << '\n';
	}
	else {
		cout << DP2[n][m] << DP1[n][m] << '\n';
	}
}