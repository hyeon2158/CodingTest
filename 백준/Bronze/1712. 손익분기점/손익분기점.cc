#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	if (B >= C) cout << -1;
	else {
		int ans = A / abs(B - C);
		cout << ans + 1;
	}
	return 0;
}