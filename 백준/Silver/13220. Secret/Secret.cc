#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque <int> num1(N);
	deque <int> num2(N);
	vector <int> cmp;
	for (size_t i = 0; i < N; i++)
	{
		cin >> num1[i];
	}
	int cnt = 1;
	while (num1[0] == num1[N - 1]) {
		num1.push_front(num1[0]);
		num1.pop_back();
		cnt++;
		if (cnt == N) break;
	}
	for (size_t i = 0; i < N; i++)
	{
		cin >> num2[i];
		if (!cmp.empty() && num1[cmp.size()] == num2[i]) cmp.push_back(num2[i]);
		else if (!cmp.empty() && num1[cmp.size()] != num2[i]) cmp.clear();
		if (cmp.empty() && num1[0] == num2[i]) cmp.push_back(num2[i]);
	}
	if (cmp.empty()) cout << "NO";
	else {
		bool decode = 1;
		for (size_t i = cmp.size(); i < N; i++)
		{
			if (num1[i] != num2[i - cmp.size()]) {
				cout << "NO"; decode = 0; break;
			}
		}
		if (decode) cout << "YES";
	}

	return 0;
}