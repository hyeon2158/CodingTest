#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int count = 1;
	int criteria = 6;

	while (N > 1)
	{
		N -= criteria;
		count++;
		criteria += 6;
	}
	cout << count;
	return 0;
}