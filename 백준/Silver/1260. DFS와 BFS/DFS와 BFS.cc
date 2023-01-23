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
	cout << curr << ' ';
	for (size_t i = 0; i < graph[curr].size(); i++)
	{
		if (!visit[graph[curr][i]]) DFS(graph[curr][i]);
	}
}

void BFS(int curr) {
	if (!visit[bfs.front()]) {
		cout << bfs.front() << ' ';
	}
	bfs.pop();
	visit[curr] = true;
	for (size_t i = 0; i < graph[curr].size(); i++)
	{
		if (!visit[graph[curr][i]]) bfs.push(graph[curr][i]);
	}
	if (bfs.empty()) {
		return;
	}
	BFS(bfs.front());
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	cin >> N >> M >> V;
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
	DFS(V);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	bfs.push(V);
	BFS(V);
	return 0;
}