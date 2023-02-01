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
queue<int> position;
void bfs(int);

void bfs(int curr) {
	position.push(curr);
	visit[curr] = 1;
	while (!position.empty())
	{
		curr = position.front();
		if (curr != K) {
			int m1 = curr - 1;
			int p1 = curr + 1;
			int m2 = curr * 2;
			if (m1 >= 0 && m1 < MAX && !visit[m1]) {
				visit[m1] = visit[curr] + 1;
				position.push(m1);
			}
			if (p1 < MAX && !visit[p1]) {
				visit[p1] = visit[curr] + 1;
				position.push(p1);
			}
			if (m2 < MAX && !visit[m2]) {
				visit[m2] = visit[curr] + 1;
				position.push(m2);
			}
		}
		else if (curr == K) {
			cout << visit[curr] - 1;
			return;
		}
		position.pop();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	bfs(N);
	return 0;
}