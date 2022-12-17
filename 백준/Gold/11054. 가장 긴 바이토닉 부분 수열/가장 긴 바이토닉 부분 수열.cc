#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> seq(N + 1);
	vector<vector<int> > DP(N + 1, vector<int>(2));
	vector<int> part(N + 1);

	for (size_t i = 1; i < N+1; i++)
	{
		int enter;
		cin >> enter;
		seq[i] = enter;
	}
	DP[1][0] = 1;
	for (size_t i = 2; i < N+1; i++)
	{
		DP[i][0] = 1;
		for (size_t j = 1; j < i; j++)
		{
			if (seq[i] > seq[j]) {
				DP[i][0] = max(DP[i][0], DP[j][0] + 1);
			}
			else if (seq[i] < seq[j]) {
				DP[i][1] = max({ DP[i][1], DP[j][1] + 1, DP[j][0] + 1 });
			}
		}
	}
	int m = 0;
	for (size_t i = 1; i < N+1; i++)
	{
		m = max({ m,DP[i][0], DP[i][1] });
	}
	cout << m;
}