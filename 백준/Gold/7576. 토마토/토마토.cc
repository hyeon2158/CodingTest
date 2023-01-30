#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 1000
#define INF 9'999'999
using namespace std;

int M, N;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<vector<int> > graph;
int visit[MAX][MAX];
queue<pair<int, int> > bfs;
void BFS(void);

void BFS(void) {
	while (!bfs.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			int n = bfs.front().first + dx[i];
			int m = bfs.front().second + dy[i];
			if (n >= 0 && m >= 0 && n < N && m < M) {
				if (visit[n][m] > visit[n - dx[i]][m - dy[i]] + 1 && graph[n][m] == 0) {
					visit[n][m] = visit[n - dx[i]][m - dy[i]] + 1;
					bfs.push({ n, m });
				}
			}
		}
		bfs.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N;
	graph.resize(N);
	fill(&visit[0][0], &visit[MAX - 1][MAX], INF);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			int ent;
			cin >> ent;
			graph[i].push_back(ent);
			if (ent == 1) {
				bfs.push(make_pair(i, j));
				visit[i][j] = 0;
			}
		}
	}
	BFS();
	int ans = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (graph[i][j] != -1) ans = max(visit[i][j], ans);
		}
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}