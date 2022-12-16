#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#define MOD 1'000'000'009
using namespace std;

typedef long long ong;


int main(void) {
	int T;
	cin >> T;

	vector<ong> DP(1'000'001);
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (size_t i = 4; i <= 1'000'000; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % MOD;
	}
	for (size_t i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << DP[n] << '\n';
	}

	return 0;
}
