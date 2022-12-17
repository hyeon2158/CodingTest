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
	vector<pair<int, int> > DP(N + 1, { -1000, -1000 });
	vector<int> part(N + 1);

	for (size_t i = 1; i < N+1; i++)
	{
		int enter;
		cin >> enter;
		seq[i] = enter;
	}
	DP[1].first = seq[1];
	DP[1].second = 0;

	for (size_t i = 1; i < N+1; i++)
	{
		DP[i].first = max(seq[i], DP[i - 1].first + seq[i]);
		DP[i].second = max(DP[i - 1].first, DP[i - 1].second + seq[i]);
	}
	int m = -1000;
	for (size_t i = 1; i < N + 1; i++)
	{
		m = max({m, DP[i].first, DP[i].second});
	}
	cout << m;
}