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
	vector<vector<int> > cost(N + 1, vector<int>(3));
	vector<vector<int> > DP_1(N + 1, vector<int>(3, 2001));
	vector<vector<int> > DP_2(N + 1, vector<int>(3, 2001));
	vector<vector<int> > DP_3(N + 1, vector<int>(3, 2001));

	for (size_t i = 1; i <= N; i++)
	{
		int R, G, B;
		cin >> R >> G >> B;
		cost[i][0] = R;
		cost[i][1] = G;
		cost[i][2] = B;
	}

	DP_1[1][0] = cost[1][0];
	DP_1[2][1] = cost[1][0] + cost[2][1];
	DP_1[2][2] = cost[1][0] + cost[2][2];
	for (size_t i = 3; i <= N; i++)
	{
		DP_1[i][0] = min(DP_1[i - 1][1], DP_1[i - 1][2]) + cost[i][0];
		DP_1[i][1] = min(DP_1[i - 1][0], DP_1[i - 1][2]) + cost[i][1];
		DP_1[i][2] = min(DP_1[i - 1][1], DP_1[i - 1][0]) + cost[i][2];
	}

	DP_2[1][1] = cost[1][1];
	DP_2[2][0] = cost[1][1] + cost[2][0];
	DP_2[2][2] = cost[1][1] + cost[2][2];
	for (size_t i = 3; i <= N; i++)
	{
		DP_2[i][0] = min(DP_2[i - 1][1], DP_2[i - 1][2]) + cost[i][0];
		DP_2[i][1] = min(DP_2[i - 1][0], DP_2[i - 1][2]) + cost[i][1];
		DP_2[i][2] = min(DP_2[i - 1][1], DP_2[i - 1][0]) + cost[i][2];
	}

	DP_3[1][2] = cost[1][2];
	DP_3[2][0] = cost[1][2] + cost[2][0];
	DP_3[2][1] = cost[1][2] + cost[2][1];
	for (size_t i = 3; i <= N; i++)
	{
		DP_3[i][0] = min(DP_3[i - 1][1], DP_3[i - 1][2]) + cost[i][0];
		DP_3[i][1] = min(DP_3[i - 1][0], DP_3[i - 1][2]) + cost[i][1];
		DP_3[i][2] = min(DP_3[i - 1][1], DP_3[i - 1][0]) + cost[i][2];
	}

	cout << min({ DP_1[N][1], DP_1[N][2], DP_2[N][0], DP_2[N][2], DP_3[N][0], DP_3[N][1] });
	return 0;
}