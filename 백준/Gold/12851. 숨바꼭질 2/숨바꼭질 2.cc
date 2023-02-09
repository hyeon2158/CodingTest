#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100'001
using namespace std;

int N, K;
int visit[MAX];
queue<pair <int, int>> position;
int cnt;
void bfs(int);
int res;

void bfs(int curr) {
	position.push({curr, 0});
	while (!position.empty())
	{
		int now = position.front().first;
		int time = position.front().second;
		position.pop();
		visit[now] = 1;
		if (cnt && res == time && now == K)
			cnt++;
		if (!cnt && now == K)
		{
			res = time;
			cnt++;
		}
		if (now - 1 >= 0 && !visit[now - 1])
			position.push({ now - 1,time + 1 });
		if (now + 1 < MAX && !visit[now + 1])
			position.push({ now + 1,time + 1 });
		if (2 * now < MAX && !visit[2 * now])
			position.push({ 2 * now,time + 1 });
	}
	cout << res << '\n';
	cout << cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	bfs(N);
	return 0;
}