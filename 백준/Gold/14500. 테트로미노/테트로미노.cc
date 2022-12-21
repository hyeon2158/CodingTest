#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int cur[4][2]{ {1, 0} , {-1, 0}, {0, 1}, {0, -1} };
int m = -1;
int N, M;
vector<vector <int> > num(500, vector<int>(500));
vector <vector <bool> > check(500, vector<bool>(500));


void decode(const int a, const int b, int cnt, int sum) {
	if (cnt == 3) {
		m = max(m, sum);
		return;
	}
	if (cnt < 3) {
		for (size_t i = 0; i < 4; i++)
		{
			if (a+cur[i][0] >= 0 && a + cur[i][0] < N && b+cur[i][1] >= 0 && b + cur[i][1] < M && !check[a + cur[i][0]][b + cur[i][1]]) {
				check[a + cur[i][0]][b + cur[i][1]] = true;
				decode(a + cur[i][0], b + cur[i][1], cnt + 1, sum + num[a + cur[i][0]][b + cur[i][1]]);
				decode(a, b, cnt + 1, sum + num[a + cur[i][0]][b + cur[i][1]]);
				check[a + cur[i][0]][b + cur[i][1]] = false;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			//int ent;
			//cin >> ent;
			//num[i][j] = ent;
			cin >> num[i][j];
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			check[i][j] = true;
			decode(i, j, 0, num[i][j]);
			check[i][j] = false;
		}
	}
	cout << m;
	return 0;
}