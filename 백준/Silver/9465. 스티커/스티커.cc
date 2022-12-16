#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	int T;
	cin >> T;


	for (size_t i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		vector<vector<int> > DP(3, vector<int>(n+1));
		vector<vector<int> > score(2, vector<int>(n+1));
		for (size_t i = 1; i < n + 1; i++)
		{
			int enter;
			cin >> enter;
			score[0][i] = enter;
		}
		for (size_t i = 1; i < n + 1; i++)
		{
			int enter;
			cin >> enter;
			score[1][i] = enter;
		}

		DP[0][1] = score[0][1];
		DP[1][1] = score[1][1];
		DP[2][1] = 0;
		for (size_t i = 2; i < n+1; i++)
		{
			DP[0][i] = max(DP[1][i - 1] + score[0][i], DP[2][i - 1] + score[0][i]);
			DP[1][i] = max(DP[0][i - 1] + score[1][i], DP[2][i - 1] + score[1][i]);
			DP[2][i] = max(DP[0][i - 1], DP[1][i - 1]);
		}

		cout << max({ DP[0][n], DP[1][n], DP[2][n] }) << '\n';
	}
	
	return 0;
}