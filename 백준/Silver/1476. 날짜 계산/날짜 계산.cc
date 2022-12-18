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

	int E, S, M;
	cin >> E >> S >> M;
	bool check = true;
	int i = 1;
	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;
	while (check) {
		if (i % 15 == E && i % 28 == S && i % 19 == M) {
			cout << i;
			check = false;
		}
		i++;
	}
	
	return 0;
}