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

	int k;
	cin >> k;
	vector<char> sign(k);
	for (size_t i = 0; i < k; i++)
	{
		cin >> sign[i];
	}
	vector<int> num(10);
	for (size_t i = 0; i < 10; i++)
	{
		num[i] = i;
	}
	vector<int> l;
	vector<int> g;
	do
	{
		bool decode = 1;
		for (size_t i = 0; i < k; i++)
		{
			if (sign[i] == '<') {
				if (num[i] > num[i + 1]) { decode = 0;  break; }
			}
			else if (sign[i] == '>') {
				if (num[i] < num[i + 1]) { decode = 0;  break; }
			}
		}
		if (decode == 1 && l.empty()) l = num;
		else if (decode == 1) g = num;
	} while (next_permutation(num.begin(), num.end()));
	for (size_t i = 0; i < k + 1; i++)
	{
		cout << g[i];
	}
	cout << '\n';
	for (size_t i = 0; i < k + 1; i++)
	{
		cout << l[i];
	}
	return 0;
}