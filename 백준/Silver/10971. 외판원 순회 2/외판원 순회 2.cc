#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N;
int cost = 100'000'000;
vector <vector <int> > city(10, vector<int>(10));

typedef unsigned long long u;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> city[i][j];
		}
	}
	
	vector<int> a(N);

	for (size_t i = 0; i < N; i++)
	{
		a[i] = i;
	}
	sort(a.begin(), a.end());
	
	do
	{
		int sum = 0;
		int decode = 1;
		for (size_t i = 0; i < N-1; i++)
		{
			if (city[a[i]][a[i + 1]]) sum += city[a[i]][a[i + 1]];
			else {
				decode = 0;
				break;
			}
		}
		if (decode) {
			if (city[a[N - 1]][a[0]]) {
				sum += city[a[N - 1]][a[0]];
				cost = min(cost, sum);
			}
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << cost;
	
	return 0;
}