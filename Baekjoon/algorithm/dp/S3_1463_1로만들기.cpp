#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int num[1'000'001]{};

int main(void) {
	int X;
	cin >> X;

	for (size_t i = 2; i <= X; i++)
	{
		num[i] = num[i - 1] + 1;

		if (i % 3 == 0) {
			num[i] = num[i] < (num[i / 3] + 1) ? num[i] : (num[i / 3] + 1);
		}
		if (i % 2 == 0) {
			num[i] = num[i] < (num[i / 2] + 1) ? num[i] : (num[i / 2] + 1);
		}
	}
	cout << num[X];
	return 0;
}