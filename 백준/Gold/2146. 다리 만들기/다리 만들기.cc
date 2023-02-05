#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 100
using namespace std;

int N;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int visit[MAX_SIZE][MAX_SIZE];
vector<vector<int>> map;
queue<pair<int, int>> bfs;
queue<pair<int, int>> res;
int cnt = 2;

void BFS(int x, int y) {
	map[x][y] = cnt;
	bfs.push({ x, y });
	while (!bfs.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			int nx = bfs.front().first + dx[i];
			int ny = bfs.front().second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (map[nx][ny] == 1) {
					bfs.push({ nx, ny });
					map[nx][ny] = cnt;
				}
			}
		}
		bfs.pop();
	}
	cnt++;
}

int ans(void) {
	int mn = 30'000;
	while (!res.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			int nx = res.front().first + dx[i];
			int ny = res.front().second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visit[nx][ny] > 1 && map[nx][ny] != map[nx - dx[i]][ny - dy[i]]) {
					mn = min(mn, visit[nx][ny] + visit[nx - dx[i]][ny - dy[i]] - 2);
				}
				if (!visit[nx][ny] && map[nx][ny] == 0) {
					map[nx][ny] = map[nx - dx[i]][ny - dy[i]];
					res.push({ nx, ny });
					visit[nx][ny] = visit[nx - dx[i]][ny - dy[i]] + 1;
				}
			}
		}
		res.pop();
	}
	return mn;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	map.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			map[i].push_back(temp);
			if (temp == 1) {
				res.push({ i, j });
				visit[i][j] = 1;
			}
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (map[i][j] == 1) {
				BFS(i, j);
			}
		}
	}
	cout << ans();
	return 0;
}