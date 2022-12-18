#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int quantity(const vector<string> a) {
	int m = 1;
	for (size_t i = 0; i < a.size(); i++)
	{
		int cnt = 1;
		for (size_t j = 0; j < a.size()-1; j++)
		{
			/*switch (a[i][j])
			{
			case 'C': C++; break;
			case 'P': P++; break;
			case 'Z': Z++; break;
			case 'Y': Y++; break;
			default:
				break;
			}*/
			if (a[i][j] == a[i][j + 1]) cnt++;
			else {
				m = max(cnt, m);
				cnt = 1;
			}
			m = max(cnt, m);
		}
	}
	for (size_t i = 0; i < a.size(); i++)
	{
		int cnt = 1;
		for (size_t j = 0; j < a.size()-1; j++)
		{
		/*	switch (a[j][i])
			{
			case 'C': C++; break;
			case 'P': P++; break;
			case 'Z': Z++; break;
			case 'Y': Y++; break;
			default:
				break;
			}*/
			if (a[j][i] == a[j+1][i]) cnt++;
			else {
				m = max(cnt, m);
				cnt = 1;
			}
			m = max(cnt, m);
		}
	}
	return m;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int high = 0;
	vector<string> candy(N);

	for (size_t i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		candy[i] = str;
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N-1; j++)
		{
			if (candy[i][j] != candy[i][j + 1]) {
				swap(candy[i][j], candy[i][j + 1]);
				high = max(high, quantity(candy));
				swap(candy[i][j], candy[i][j + 1]);
			}
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N - 1; j++)
		{
			if (candy[j][i] != candy[j+1][i]) {
				swap(candy[j][i], candy[j+1][i]);
				high = max(high, quantity(candy));
				swap(candy[j][i], candy[j+1][i]);
			}
		}
	}
	cout << high;
	return 0;
}