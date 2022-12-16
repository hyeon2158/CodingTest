#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<vector<int> > DP(N + 1, vector<int>(3));

	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;

	for (size_t i = 2; i <= N; i++)
	{
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 9901;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % 9901;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
	}
	cout << (DP[N][0] + DP[N][1] + DP[N][2]) % 9901;
	return 0;
}