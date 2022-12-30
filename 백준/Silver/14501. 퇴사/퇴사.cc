#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef unsigned long long ong;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	vector<pair<int, int> > price(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> price[i].first >> price[i].second;
	}
	vector<int> DP(N+5);
	
	for (int i = 0; i < N; i++)
	{
		if (i + price[i].first <= N) DP[i + price[i].first] = max(DP[i + price[i].first], DP[i] + price[i].second);
		DP[i + 1] = max(DP[i + 1], DP[i]);
	}
	sort(DP.begin(), DP.end());
	cout << DP.back();
	return 0;
}
