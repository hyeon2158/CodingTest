#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef unsigned long long ong;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	vector<vector <int> > abi(N+1, vector<int>(N+1));
	int sum = 0;
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= N; j++)
		{
			cin >> abi[i][j];
			sum += abi[i][j];
		}
	}
	vector<int> combi(N);
	int res = 1'000'000;
	for (size_t i = 0; i < N/2; i++)
	{
		combi[i] = 1;
	}
	do
	{
		int start = 0;
		int link = 0;
		for (size_t i = 0; i < N-1; i++)
		{
			for (size_t j = i+1; j < N; j++)
			{
				if (combi[i] == 1 && combi[j] == 1)
				start += abi[i+1][j+1] + abi[j+1][i+1];
				else if (combi[i] == 0 && combi[j] == 0)
				link += abi[i + 1][j + 1] + abi[j + 1][i + 1];
			}
		}
		 res = min (res, abs(link - start));
	} while (prev_permutation(combi.begin(), combi.end()));

	cout << res;
	return 0;
}
