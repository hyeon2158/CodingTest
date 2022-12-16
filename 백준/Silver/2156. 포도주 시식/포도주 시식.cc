#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> amount(n);
	for (size_t i = 0; i < n; i++)
	{
		int ent;
		cin >> ent;
		amount[i] = ent;
	}

	vector<vector<int> > DP(2, vector<int>(n));
	
	if (n == 1) {
		cout << amount[0];
		return 0;
	}
	DP[0][0] = amount[0];
	DP[0][1] = amount[1];
	DP[1][1] = amount[0] + amount[1];
	DP[0][2] = max(DP[0][0], DP[1][0]) + amount[2];
	DP[1][2] = DP[0][1] + amount[2];

	for (size_t i = 3; i < n; i++)
	{
		DP[0][i] = max({DP[0][i - 2], DP[1][i - 2], DP[0][i-3], DP[1][i-3]}) + amount[i];
		DP[1][i] = DP[0][i - 1] + amount[i];
	}

	cout << max({ DP[0][n - 1], DP[1][n - 1], DP[1][n - 2] });

	return 0;
}
