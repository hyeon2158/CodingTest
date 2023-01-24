#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<vector<int>> graph;
bool visit[1001]{};
queue<int> bfs;

void DFS(int curr) {
	visit[curr] = true;
	//cout << curr << ' ';
	for (size_t i = 0; i < graph[curr].size(); i++)
	{
		if (!visit[graph[curr][i]]) DFS(graph[curr][i]);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int ans = 0;
	graph.resize(N+1);
	for (size_t i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (size_t i = 0; i < graph.size(); i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	for (size_t i = 1; i < N+1; i++)
	{
		if (!visit[i]) { DFS(i); ans++; }
	}
	cout << ans;
	return 0;
}