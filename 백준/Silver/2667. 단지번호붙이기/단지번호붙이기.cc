#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> cnt;
int number = 0;
vector<vector<char>> graph;
bool visit[25][25];
queue<pair <int, int> > bfs;

void BFS(int, int);

void BFS(int a, int b) {
	visit[a][b] = 1;
	bfs.push({ a, b });
	number++;
	cnt.push_back(1);
	while (!bfs.empty()) {
		a = bfs.front().first;
		b = bfs.front().second;
		bfs.pop();
		if (a > 0 && !visit[a - 1][b] && graph[a - 1][b] == '1') {
			bfs.push({ a - 1, b });
			visit[a - 1][b] = 1;
			cnt.back()++;
		}
		if (b > 0 && !visit[a][b - 1] && graph[a][b - 1] == '1') {
			bfs.push({ a, b  - 1 });
			visit[a][b - 1] = 1;
			cnt.back()++;
		}
		if (a < N-1  && !visit[a + 1][b] && graph[a + 1][b] == '1') {
			bfs.push({ a + 1, b });
			visit[a + 1][b] = 1;
			cnt.back()++;
		}
		if (b < N-1 && !visit[a][b + 1] && graph[a][b + 1] == '1') {
			bfs.push({ a , b + 1 });
			visit[a][b + 1] = 1;
			cnt.back()++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	graph.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			char a;
			cin >> a;
			graph[i].push_back(a);
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (graph[i][j] == '1' && !visit[i][j]) {
				BFS(i, j);
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << number << '\n';
	for (size_t i = 0; i < cnt.size(); i++)
	{
		cout << cnt[i] << '\n';
	}
	return 0;
}