#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#define MOD 10'007
using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<vector<int> > DP(N + 1, vector<int>(10));

	for (size_t i = 0; i < 10; i++)
	{
		DP[1][i] = 1;
	}
	for (size_t i = 2; i <= N; i++)
	{
		DP[i][0] = DP[i - 1][0];
		for (size_t j = 1; j < 10; j++)
		{
			DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
		}
	}
	int sum = 0;
	for (size_t i = 0; i < 10; i++)
	{
		sum += DP[N][i];
	}
	cout << sum % MOD;

	return 0;
}