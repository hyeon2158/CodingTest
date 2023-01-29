#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100
using namespace std;

int N, M;
vector<vector<char> > graph;
int visit[MAX][MAX];
queue<pair<int, int>> bfs;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void BFS(int, int);

void BFS(int x, int y) {
	bfs.push({ x, y });
	visit[x][y] = 1;
	while (!bfs.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			x = bfs.front().first + dx[i];
			y = bfs.front().second + dy[i];
			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (x == N - 1 && y == M - 1) { cout << visit[x - dx[i]][y - dy[i]] + 1; return; }
				else if (graph[x][y] == '1' && visit[x][y] == 0) {
					visit[x][y] = visit[x - dx[i]][y - dy[i]] + 1;
					bfs.push({ x, y });
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
	
	cin >> N >> M;

	graph.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			char ent;
			cin >> ent;
			graph[i].push_back(ent);
		}
	}
	BFS(0, 0);
	return 0;
}
