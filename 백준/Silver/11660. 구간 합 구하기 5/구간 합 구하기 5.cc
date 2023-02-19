#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 1024
using namespace std;

int N, M;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			sum[i][j] = map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {

		for (int j = 2; j <= N; j++) {
			sum[i][j] += sum[i][j - 1];
		}
	}

	int x1, y1, x2, y2;

	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int ans = 0;
			for (int k = x1; k <= x2; k++) {
				ans += sum[k][y2];
			}

			for (int k = x1; k <= x2; k++) {
				ans -= sum[k][y1 - 1];
			}
		cout << ans << "\n";
	}
}