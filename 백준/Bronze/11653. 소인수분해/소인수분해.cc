#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int prime[10'000'001]{};

int main(void) {
	int N;
	cin >> N;
	if (N == 1) {
		return 0;
	}
	for (size_t i = 1; i <= 10'000'000; i++)
	{
		prime[i] = i;
	}
	for (size_t i = 2; i <= sqrt(10'000'000); i++)
	{
		if (prime[i]) {
			for (size_t j = i*2; j <= 10'000'000; j+=i)
			{
				prime[j] = 0;
			}
		}
	}
	int size = N;
	int i = 2;
	while (!prime[N]) {
		if (prime[i]) {
			if (!(N % i)) {
				cout << i << '\n';
				N /= i;
			}
			else i++;
		}
		else i++;
	}
	cout << N;
	return 0;
}