#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> fr;
bool visit[2000]{};
int N, M;
int ans = 0;

void DFS(int curr, int cnt) {
	visit[curr] = 1;
	if (cnt == 4) { ans = 1; return; }
	for (size_t i = 0; i < fr[curr].size(); i++)
	{
		if (!visit[fr[curr][i]]) {
			DFS(fr[curr][i], cnt+1);
		}
	}
	visit[curr] = 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	fr.resize(N);
	
	for (size_t i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	for (size_t i = 0; i < N; i++)
	{
		DFS(i, 0);
		if (ans) break;
	}
	cout << ans;
	return 0;
}