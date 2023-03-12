#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int cnt = 0;
		cin >> cnt;
		vector<string> city;
		city.resize(cnt);
		for (size_t i = 0; i < cnt; i++)
		{
			cin >> city[i];
		}
		int ans = 1;
		sort(city.begin(), city.end());
		for (size_t i = 1; i < cnt; i++)
		{
			if (city[i] == city[i - 1]) continue;
			else ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}