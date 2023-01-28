#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 50

using namespace std;

int w, h;
vector<vector<int>> graph;
int visit[MAX][MAX];
queue<pair<int, int>> bfs;
int dx[3] = { 1, 0, -1 };
int dy[3] = { 1, 0, -1 };
int number = 0;

void BFS(int, int);

void BFS(int x, int y) {
	bfs.push({x, y});
	visit[x][y] = 1;
	while (!bfs.empty())
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				x = bfs.front().first + dx[i];
				y = bfs.front().second + dy[j];
				if (i == 1 && j == 1) continue;
				if (x >= 0 && y >= 0 && x < h && y < w) {
					if (!visit[x][y] && graph[x][y] == 1) {
						bfs.push({ x, y });
						visit[x][y] = 1;
					}
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

	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;
		graph.resize(h); 
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				int ent;
				cin >> ent;
				graph[i].push_back(ent);
			}
		}
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				if (!visit[i][j] && graph[i][j] == 1) {
					BFS(i, j);
					number++;
				}
			}
		}
		cout << number << '\n';
		for (size_t i = 0; i < graph.size(); i++)
		{
			graph[i].clear();
		}
		graph.clear();
		number = 0;
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}
