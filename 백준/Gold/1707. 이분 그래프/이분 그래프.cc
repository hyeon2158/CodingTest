#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
#define RED 1
#define BLUE 2

int V, E;
vector<vector<int>> graph;
int visit[20001];
queue<int> bfs;

void BFS(int curr) {
	visit[curr] = RED;
	bfs.push(curr);
	while (!bfs.empty())
	{
		curr = bfs.front();
		for (size_t i = 0; i < graph[curr].size(); i++)
		{
			if (!visit[graph[curr][i]]) { 
				if (visit[curr] == RED) visit[graph[curr][i]] = BLUE;  
				else visit[graph[curr][i]] = RED;
				bfs.push(graph[curr][i]); 
			}
		}
		bfs.pop();
	}
}
bool check() {
	for (size_t i = 1; i <= V; i++)
	{
		for (size_t j = 0; j < graph[i].size(); j++)
		{
			if (visit[i] == visit[graph[i][j]]) return false;
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	for (size_t i = 0; i < K; i++)
	{
		cin >> V >> E;

		for (size_t i = 0; i < E; i++)
		{
			graph.resize(V+1);
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (size_t i = 1; i <= V; i++)
		{
			if (!visit[i]) BFS(i);
		}
		if (check()) cout << "YES\n";
		else cout << "NO\n";

		for (size_t i = 1; i <= V; i++)
		{
			graph[i].clear();
		}
		memset(visit, false, sizeof(visit));
		//graph.clear();
	}

	return 0;
}