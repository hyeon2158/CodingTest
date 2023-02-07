#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100
using namespace std;

int M, N, K;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<vector<int>> graph;
int visit[MAX][MAX];
queue<pair <int, int>> bfs;
vector<int> area;
int num;

void BFS(int n, int m) {
	num++;
	bfs.push({ n, m });
	visit[n][m] = 1;
	area.push_back(1);
	while (!bfs.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			n = bfs.front().first + dx[i];
			m = bfs.front().second + dy[i];
			if (n >= 0 && m >= 0 && n < N && m < M) {
				if (visit[n][m] == 0 && graph[n][m] == 0) {
					bfs.push({ n, m });
					visit[n][m] = visit[n - dx[i]][m - dy[i]];
					area.back()++;
				}
			}
		}
		bfs.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;
	graph.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			graph[i].push_back(0);
		}
	}
	for (size_t i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (size_t i = a; i < c; i++)
		{
			for (size_t j = b; j < d; j++)
			{
				graph[i][j] = 1;
			}
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (graph[i][j] == 0 && visit[i][j] == 0) {
				BFS(i, j);
			}
		}
	}
	cout << num << '\n';
	sort(area.begin(), area.end());
	for (size_t i = 0; i < area.size(); i++)
	{
		cout << area[i] << ' ';
	}
	return 0;
}