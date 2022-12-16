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
	vector<vector<int> > DP(n+1, vector<int>(n+1));
	vector<vector<int> > tri(n + 1, vector<int>(n + 1));

	for (size_t i = 1; i < n+1; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			int enter;
			cin >> enter;
			tri[i][j] = enter;
		}
	}
	if (n == 1) {
		cout << tri[1][1];
		return 0;
	}
	DP[1][1] = tri[1][1];
	DP[2][1] = tri[1][1] + tri[2][1];
	DP[2][2] = tri[1][1] + tri[2][2];

	for (size_t i = 3; i < n+1; i++)
	{
		DP[i][1] = DP[i - 1][1] + tri[i][1];
		for (size_t j = 2; j <= i-1; j++)
		{
			DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + tri[i][j];
		}
		DP[i][i] = DP[i - 1][i - 1] + tri[i][i];
	}
	sort(DP[n].begin(), DP[n].end());
	cout << DP[n].back();
	return 0;
}