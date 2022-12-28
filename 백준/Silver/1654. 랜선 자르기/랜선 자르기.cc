#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long K, N;
	long long sum = 0;
	vector <long long> len;
	cin >> K >> N;

	for (long long i = 0; i < K; i++)
	{
		long long cable;
		cin >> cable;
		sum += cable;
		len.push_back(cable);
	}

	long long ratio = sum / N;
	long long answer = 0;

	long long startfind = 1;
	long long current = 0;
	while (startfind <= ratio) {
		current = (startfind + ratio) / 2;
		int decode = 0;
		for (long long j = 0; j < K; j++)
		{
			decode = decode + len[j] / current;
		}

		if (decode >= N) {
			answer = (answer > current ? answer : current);
			startfind = current + 1;
		}
		else {
			ratio = current - 1;
		}
	}
	cout << answer;
	return 0;
}