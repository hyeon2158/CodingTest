#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> t(100'001);
	int N, K;
	cin >> N >> K;
	int ans = -100 * K;
	for (size_t i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		t[i] = t[i - 1] + tmp;
	}
	for (size_t i = K; i <= N; i++)
	{
		ans = max(ans, t[i] - t[i - K]);
	}
	if (N == K) cout << t[N];
	else cout << ans;
	return 0;
}