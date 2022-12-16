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
	vector<int> DP(N + 1);
	vector<int> part(N + 1);

	for (size_t i = 1; i < N+1; i++)
	{
		int enter;
		cin >> enter;
		seq[i] = enter;
	}
	DP[1] = 1;
	part[0] = seq[1];
	for (size_t i = 2; i < N+1; i++)
	{
		int cnt = lower_bound(part.begin(), part.end(), seq[i], greater<int>())-part.begin();
		DP[i] = cnt+1;
		if (part[cnt] < seq[i]) part[cnt] = seq[i];
	}
	sort(DP.begin(), DP.end());
	cout << DP[N];
}