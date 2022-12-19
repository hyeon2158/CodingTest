#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool decode(int num, const vector<int> a) {
	if (num == 0 && a[0] != 0) return false;
	while (num)
	{
		if(num % 10 != a[num % 10]) return false;
		num /= 10;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<int> num(10);

	for (size_t i = 0; i < 10; i++)
	{
		num[i] = i;
	}

	for (size_t i = 0; i < M; i++)
	{
		int ent;
		cin >> ent;
		num[ent] = 0;
		if (ent == 0) num[ent] = 1;
	}
	
	int m = abs(N-100);
	for (int i = 0; i <= 999'999; i++)
	{
		if (decode(i, num)) {
			int cnt = i;
			int ncount = abs(N - i) + 1;
			while (cnt/10)
			{
				ncount++;
				cnt /= 10;
			}
			m = min(m, ncount);
		}
	}
	cout << m;
	return 0;
}