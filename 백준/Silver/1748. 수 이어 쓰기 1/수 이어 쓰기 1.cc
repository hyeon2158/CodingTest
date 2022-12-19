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
	int cnt = 0;
	if (N >= 10'000'000) {
		int a = N - 10'000'000;
		cnt += a * 8;
		if (N == 100'000'000) cnt++;
		N = 10'000'000;
	}

	for (size_t i = 1; i <= N; i++)
	{
		string str = to_string(i);
		cnt += str.size();
	}
	cout << cnt;
	return 0;
}