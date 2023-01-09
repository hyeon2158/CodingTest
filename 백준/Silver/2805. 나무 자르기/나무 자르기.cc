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

	long long N, M;
	cin >> N >> M;
	vector<long long> wood(N);

	for (long long i = 0; i < N; i++)
	{
		cin >> wood[i];
	}
	sort(wood.begin(), wood.end());
	long long height = 0;
	long long start = 0;
	long long end = 1000000000;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cut = 0;
		for (long long i = 0; i < N; i++)
		{
			if (wood[i] > mid) cut += (wood[i] - mid);
		}
		if (cut >= M) {
			height = max(height, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << height;
	return 0;
}