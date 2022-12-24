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

	while(1)
	{
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> lotto(k);
		for (size_t i = 0; i < k; i++)
		{
			cin >> lotto[i];
		}
		vector<int> combi(k);
		for (size_t i = 0; i < 6; i++)
		{
			combi[i] = 1;
		}
		do
		{
			for (size_t i = 0; i < k; i++)
			{
				if (combi[i]) cout << lotto[i] << ' ';
			}
			cout << '\n';
		} while (prev_permutation(combi.begin(), combi.end()));
		cout << '\n';
	}
	return 0;
}