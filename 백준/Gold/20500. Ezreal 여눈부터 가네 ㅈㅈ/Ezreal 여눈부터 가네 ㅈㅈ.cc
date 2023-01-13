#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

#define MOD 1'000'000'007
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<long long> > DP(N, vector<long long>(3));
	DP[0][1] = 1;
	DP[0][2] = 1;

	for (size_t i = 1; i < N; i++)
	{
		DP[i][0] = (DP[i - 1][1] + DP[i - 1][2]) % MOD;
		DP[i][1] = (DP[i - 1][2] + DP[i - 1][0]) % MOD;
		DP[i][2] = (DP[i - 1][1] + DP[i - 1][0]) % MOD;
	}
	if (N == 1) cout << 0;
	else {
		cout << DP[N - 2][1];
	}
	return 0;
}