#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int> > DP(N+1, vector<int>(5));

	DP[1][0] = 0; //위에서 1칸
	DP[1][1] = 0; //아래서 1칸
	DP[1][2] = 1; //위에서 2칸
	DP[1][3] = 1; //아래서 2칸
	DP[1][4] = 0; //꽉채워짐
	DP[0][4] = 1;
	for (size_t i = 2; i <= N; i++)
	{
		DP[i][0] = DP[i - 1][3];
		DP[i][1] = DP[i - 1][2];
		DP[i][2] = DP[i - 1][4] + DP[i - 1][1];
		DP[i][3] = DP[i - 1][4] + DP[i - 1][0];
		DP[i][4] = DP[i][0] + DP[i][1] + DP[i-2][4];
	}

	cout << DP[N][4];

	return 0;
}