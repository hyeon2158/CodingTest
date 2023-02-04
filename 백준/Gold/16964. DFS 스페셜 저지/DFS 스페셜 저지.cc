#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 100'000
using namespace std;

int N;
vector<vector<int>> graph;
int visit[MAX_SIZE];
int order[MAX_SIZE];
vector<int> seq;
bool isRight;
int cnt = 0;

void dfs(int);
bool cmp(const int&, const int&);

bool cmp(const int& a, const int& b) {
	return order[a] < order[b];
}

void dfs(int a) {
	if (a != seq[cnt]) {
		isRight = 1;
		return;
	}
	visit[a] = 1;
 	for (size_t i = 0; i < graph[a].size(); i++)
	{
		if (visit[graph[a][i]] == 0) {
			cnt++;
			dfs(graph[a][i]);
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	graph.resize(N);
	for (size_t i = 0; i < N-1; i++)
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
		seq.push_back(temp - 1);
		order[temp - 1] = i + 1;
	}
	for (size_t i = 0; i <= N-1; i++)
	{
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	dfs(0);
	if (isRight) cout << 0;
	else cout << 1;
	
	return 0;
}