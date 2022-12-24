#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N;
int cost = 100'000'000;
vector <vector <int> > city(10, vector<int>(10));
vector <bool> visit(10);

void DFS(int curr, int cnt, int start, int sum) {
	if (cnt == N) {
		if (city[curr][start])
		{
			sum += city[curr][start];
			cost = min(cost, sum);
		}
	}
	else {
		for (size_t i = 0; i < N; i++)
		{
			if (!visit[i] && city[curr][i]) {
				visit[i] = true;
				sum += city[curr][i];
				if (cost > sum)
				DFS(i, cnt + 1, start, sum);
				visit[i] = false;
				sum -= city[curr][i];
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> city[i][j];
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		visit[i] = true;
		DFS(i, 1, i, 0);
		visit[i] = false;
	} 
	cout << cost;
	return 0;
}