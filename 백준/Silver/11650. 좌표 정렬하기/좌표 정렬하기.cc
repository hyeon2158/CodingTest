#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_SIZE 50
using namespace std;

int N, L, R;
bool visit[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
vector<vector<int> > map;
vector <pair<int, int>> v;

//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0, -1 };

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), cmp);
	for (size_t i = 0; i < N; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}