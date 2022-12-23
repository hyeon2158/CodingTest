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

	int N, M;
	cin >> N >> M;

	vector <int> num;
	//vector <bool> visit(8);

	for (size_t i = 0; i < N; i++)
	{
		int ent;
		cin >> ent;
		num.push_back(ent);
	}
	sort(num.begin(), num.end());
	vector <int> pre;
	do
	{
		bool decode = true;
		vector<int> curr(M);
		for (size_t i = 0; i < M; i++)
		{
			curr[i] = num[i];
		}
		if (pre == curr) continue;
		for (size_t i = 0; i < M - 1; i++)
		{
			if (curr[i] > curr[i + 1]) {
				decode = false;
				break;
			}
		}
		if (decode) {
			for (size_t i = 0; i < M; i++)
			{
				cout << curr[i] << ' ';
			}
			cout << '\n';
		}
		pre = curr;
	} while (next_permutation(num.begin(), num.end()));
}