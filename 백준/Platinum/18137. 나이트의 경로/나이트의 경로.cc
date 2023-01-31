#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 1000
#define pii pair<long long, long long>
using namespace std;

int k;
long long resx, resy;
int mov = 0;
int visit[MAX][MAX];
queue<pii> knight;
int dx[] = { -1, -2,  1, -2, 2, -1, 2, 1};
int dy[] = { -2,  -1, -2, 1, -1, 2, 1, 2};

void bfs(long long, long long);

void bfs(long long x, long long y) {
	knight.push({ x, y });
	visit[x][y] = 1;
	while (!knight.empty()) {
		if (mov == k) break;
		for (size_t i = 0; i < 8; i++)
		{
			x = knight.front().first + dx[i];
			y = knight.front().second + dy[i];
			resx = x;
			resy = y;
			if (x >= 0 && y >= 0) {
				if (!visit[x][y]) {
					knight.push({ x, y });
					visit[x][y] = 1;
					mov++;
					break;
				}
			}
		}
		knight.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	if (k == 0) cout << 1;
	else {
		bfs(0, 0);
		long long res = (resx + resy + 1) *(resx + resy) / 2 + resy + 1;
		cout << res;
	}
	return 0;
}