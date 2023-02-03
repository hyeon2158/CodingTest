#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 100'000
using namespace std;

int N;
int visit[MAX_SIZE];
queue<int> sj;
vector<vector<int>> graph;
int seq[MAX_SIZE];
queue<int> sq;

bool cmp(const int& a, const int& b) {
	return seq[a] < seq[b];
}

bool bfs(int);

bool bfs(int a) {
	sq.pop();
	sj.push(a);
	visit[a] = 1;
	while (!sj.empty())
	{
		a = sj.front();
		for (size_t i = 0; i < graph[a].size(); i++)
		{
			if (!visit[graph[a][i]] && graph[a][i] == sq.front()) {
				sj.push(graph[a][i]);
				visit[graph[a][i]] = visit[a] + 1;
				sq.pop();
			}
		}
		sj.pop();
	}
	if (sq.empty()) return true;
	else return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	graph.resize(N);
	for (size_t i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	for (size_t i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		seq[temp-1] = i + 1;
		sq.push(temp - 1);
	}
	for (size_t i = 0; i < N; i++)
	{
		sort(graph[i].begin(), graph[i].end(), cmp);
	}
	if (sq.front() != 0) cout << 0;
	else {
		if (bfs(0)) cout << 1;
		else cout << 0;
	}
	return 0;
}