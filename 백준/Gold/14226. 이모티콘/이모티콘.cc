#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 2001
using namespace std;

int S;
int t;
queue<pair<int, int>> q;
int visit[MAX][MAX];

void bfs(int curr) {
	q.push({ curr, 0 });
	visit[curr][0] = 1;
	while (!q.empty()) {
		int q_size = q.size();
		for (size_t i = 0; i < q_size; i++)
		{
			int nq = q.front().first;
			int clip = q.front().second;
			if (S == nq) {
				cout << t;
				return;
			}
			if (nq + clip < MAX && clip != 0 && !visit[nq+clip][clip]) {
				visit[nq + clip][clip] = 1;
				q.push({ nq + clip, clip }); 
			}
			if (nq > 1 && !visit[nq - 1][clip]) {
				visit[nq - 1][clip] = 1;
				q.push({ nq - 1, clip });
			}
			if (clip != nq && !visit[nq][nq]) {
				visit[nq][nq] = 1;
				q.push({ nq, nq }); 
			}
			q.pop();
		}
		t++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> S;
	bfs(1);
	return 0;
}