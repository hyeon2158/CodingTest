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

	int L, C;
	cin >> L >> C;
	vector<char> word(C);
	vector<int> combi(C);
	for (size_t i = 0; i < C; i++)
	{
		cin >> word[i];
	}
	for (size_t i = 0; i < L; i++)
	{
		combi[i] = 1;
	}
	sort(word.begin(), word.end());
	do
	{
		int cnt = 0;
		string password;
		for (size_t i = 0; i < C; i++)
		{
			if (combi[i]) {
				password += word[i];
				if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
					cnt++;
			}
		}
		if (cnt && L - cnt >= 2) cout << password << '\n';
	} while (prev_permutation(combi.begin(), combi.end()));
	return 0;
}