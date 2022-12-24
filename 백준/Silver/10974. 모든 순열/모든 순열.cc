#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> seq;
	for (size_t i = 1; i < N+1; i++)
	{
		seq.push_back(i);
	}
	do
	{
		for (size_t i = 0; i < N; i++)
		{
			cout << seq[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(seq.begin(), seq.end()));
	return 0;
}