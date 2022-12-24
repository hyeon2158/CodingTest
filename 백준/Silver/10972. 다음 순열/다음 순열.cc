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
	for (size_t i = 0; i < N; i++)
	{
		int ent;
		cin >> ent;
		seq.push_back(ent);
	}
	bool pos = next_permutation(seq.begin(), seq.end());
	if (!pos) cout << -1;
	else {
		for (size_t i = 0; i < N; i++)
		{
			cout << seq[i] << ' ';
		}
	}
	return 0;
}
