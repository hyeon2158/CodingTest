#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define MAX_SIZE 100
using namespace std;

int N, M;
int visit[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
vector<vector<char> > map;
queue <pair<int, int>> q;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int x, int y) {
	visit[x][y] = 0;
	check[x][y] = 1;
	q.push({ x, y });

	while (!q.empty()) {
		for (size_t i = 0; i < 4; i++)
		{
			int nx = dx[i] + q.front().first;
			int ny = dy[i] + q.front().second;
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[nx][ny] == '1' && check[nx][ny] == 0) {
				visit[nx][ny] = visit[nx - dx[i]][ny - dy[i]] + 1;
				check[nx][ny] = 1;
				q.push({ nx, ny });
			}
			else if (map[nx][ny] == '1' && check[nx][ny] != 0) {
				if (visit[nx - dx[i]][ny - dy[i]] + 1 < visit[nx][ny]) {
					visit[nx][ny] = visit[nx - dx[i]][ny - dy[i]] + 1;
					check[nx][ny] = 1;
					q.push({ nx, ny });
				}
				else continue;
			}
			else if (map[nx][ny] == '0') {
				if (visit[nx - dx[i]][ny - dy[i]] < visit[nx][ny]) {
					visit[nx][ny] = visit[nx - dx[i]][ny - dy[i]];
					check[nx][ny] = 1;
					q.push({ nx, ny });
				}
				else if (check[nx][ny] == 0) {
					visit[nx][ny] = visit[nx - dx[i]][ny - dy[i]];
					check[nx][ny] = 1;
					q.push({ nx, ny });
				}
				else continue;
			}
		}
		q.pop();
	}

	cout << visit[M-1][N-1];
}
int main() {
	cin >> N >> M;

	map.resize(M);

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			char tmp;
			cin >> tmp;
			map[i].push_back(tmp);
		}
	}
	bfs(0, 0);
	return 0;
}