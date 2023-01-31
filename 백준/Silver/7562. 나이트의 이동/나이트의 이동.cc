#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 300
#define pii pair<int, int>
using namespace std;

int l;
int resx, resy;
int currx, curry;
vector<vector<int>> graph;
int visit[MAX][MAX];
queue<pii> knight;
int dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

void bfs(int, int);
void ini(void);

void bfs(int x, int y) {
	knight.push({ x, y });
	visit[x][y] = 1;
	while (!knight.empty()) {
		for (size_t i = 0; i < 8; i++)
		{
			x = knight.front().first + dx[i];
			y = knight.front().second + dy[i];
			if (x >= 0 && y >= 0 && x < l && y < l) {
				if (!visit[x][y]) {
					if (x == resx && y == resy) {
						cout << visit[x - dx[i]][y - dy[i]] << "\n";
						return;
					}
					knight.push({ x, y });
					visit[x][y] = visit[x - dx[i]][y - dy[i]] + 1;
				}
			}
		}
		knight.pop();
	}
}
void ini(void) {
	memset(visit, 0, sizeof(visit));
	for (size_t i = 0; i < l; i++)
	{
		graph[i].clear();
	}
	graph.clear();
	while(!knight.empty()) {
		knight.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;

	for (size_t i = 0; i < t; i++)
	{
		cin >> l;
		graph.resize(l);
		for (size_t i = 0; i < l; i++)
		{
			for (size_t j = 0; j < l; j++)
			{
				graph[i].push_back(1);
			}
		}
	
		cin >> currx >> curry;
		cin >> resx >> resy;
		if (currx == resx && curry == resy) cout << 0 << '\n';
		else bfs(currx, curry);
		ini();
	}
	return 0;
}