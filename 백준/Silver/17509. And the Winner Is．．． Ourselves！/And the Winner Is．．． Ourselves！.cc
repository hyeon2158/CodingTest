#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int,int>> tp;
	for (size_t i = 0; i < 11; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tp.push_back({ tmp1, tmp2 });
	}
	sort(tp.begin(), tp.end());

	int sum[12]{};
	sum[0] = tp[0].first;
	for (size_t i = 1; i < 11; i++)
	{
		sum[i] += sum[i-1] + tp[i].first;
	}
	int ans = 0;
	for (size_t i = 0; i < 11; i++)
	{
		ans += sum[i];
	}
	for (size_t i = 0; i < 11; i++)
	{
		ans += tp[i].second * 20;
	}
	cout << ans;
	return 0;
}