#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100'001
using namespace std;
vector<int> tree[MAX];
int parent[MAX];
int visit[MAX];
void preorder(int curr) {
	visit[curr] = 1;
	for (size_t i = 0; i < tree[curr].size(); i++)
	{
		if (!visit[tree[curr][i]]) {
			parent[tree[curr][i]] = curr;
			preorder(tree[curr][i]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (size_t i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	preorder(1);
	for (size_t i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;
}