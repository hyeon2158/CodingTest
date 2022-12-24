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
	int sum = -2000;
	vector<int> seq;
	for (size_t i = 0; i < N; i++)
	{
		int ent;
		cin >> ent;
		seq.push_back(ent);
	}
	sort(seq.begin(), seq.end(), greater<int>());
	do
	{
		int temp = 0;
		for (size_t i = 0; i < N - 1; i++)
		{
			temp += abs((seq[i] - seq[i + 1]));
		}
		sum = max(sum, temp);
	} while (prev_permutation(seq.begin(), seq.end()));
	
	cout << sum;
	return 0;
}