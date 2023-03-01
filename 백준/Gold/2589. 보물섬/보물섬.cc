#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_SIZE 50
using namespace std;

int len, hei;
int visit[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
vector<vector<char> > map;
queue <pair<int, int>> q;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int les;

void bfs(int x, int y) {
	check[x][y] = 1;
	visit[x][y] = 0;
	q.push({ x, y });
	while (!q.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			int nx = dx[i] + q.front().first;
			int ny = dy[i] + q.front().second;
			if (nx < 0 || ny < 0 || nx >= hei || ny >= len) continue;
			if (map[nx][ny] == 'W') continue;
			else if (check[nx][ny] == 0) {
				visit[nx][ny] = visit[nx - dx[i]][ny - dy[i]] + 1;
				check[nx][ny] = 1;
				les = max(les, visit[nx][ny]);
				q.push({ nx, ny });
			}
		}
		q.pop();
	}
}

int main() {
	cin >> hei >> len;

	map.resize(hei);

	for (size_t i = 0; i < hei; i++)
	{
		for (size_t j = 0; j < len; j++)
		{
			char tmp;
			cin >> tmp;
			map[i].push_back(tmp);
		}
	}
	for (size_t i = 0; i < hei; i++)
	{
		for (size_t j = 0; j < len; j++)
		{
			if (map[i][j] == 'L') {
				bfs(i, j);
			}
			memset(check, 0, sizeof(check));
		}
	}
	cout << les;
	return 0;
}