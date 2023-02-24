#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 50
using namespace std;

vector<vector<char>> room(MAX, vector<char>(MAX));
int N, M;

int main(void)
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> M;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> room[i][j];
		}
	}
	
	int cnt = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 1; j < M; j++)
		{
			if (room[i][j] == '|' && room[i][j - 1] == '-') cnt++;
		}
		if (room[i][M - 1] == '-') cnt++;
	}

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 1; j < N; j++)
		{
			if (room[j][i] == '-' && room[j - 1][i] == '|') cnt++;
		}
		if (room[N - 1][i] == '|') cnt++;
	}
	cout << cnt;
	return 0;
}