#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int prime[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (size_t i = 2; i <= 1000000; i++)
	{
		prime[i] = i;
	}
	for (size_t i = 2; i <= sqrt(1000000); i++)
	{
		if (prime[i] == 0) continue;
		else {
			for (size_t j = i * 2; j <= 1000000; j += i)
			{
				prime[j] = 0;
			}
		}
	}

	int enter = 1;
	while (enter != 0)
	{
		cin >> enter;

		for (size_t i = 3; i <= enter / 2; i++)
		{
			if (prime[i]) {
				int dif = enter - i;
				if (prime[dif]) {
					cout << enter << " = " << i << " + " << dif << '\n';
					break;
				}
			}
			if (i == enter / 2) cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}