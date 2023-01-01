#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef unsigned long long ong;

int N;
int sum = 0;

vector<vector <int> > abi(21, vector<int>(21));
vector<bool> check(21);
vector<int> DP(21, 100'000);
void DFS(int pos, int st) {
	int start = 0;
	int link = 0;
	int temp = 0;
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = i+1; j <= N; j++)
		{
			if (check[i] && check[j]) start += abi[i][j] + abi[j][i];
			if (!check[i] && !check[j]) link += abi[i][j] + abi[j][i];
		}
	}
	temp = start - link;
	if (temp < DP[st]) {
		DP[st] = min(DP[st],abs(temp));
		for (size_t i = pos; i < N; i++)
		{
			if (!check[i]) {
				check[i] = true;
				DFS(i + 1, st);
				check[i] = false;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= N; j++)
		{
			cin >> abi[i][j];
			sum += abi[i][j];
		}
	}
	for (size_t i = 1; i <= N; i++)
	{
		check[i] = true;
		DFS(i + 1, i);
		check[i] = false;
	}
	sort(DP.begin(), DP.end());
	cout << DP[0];
	return 0;
}