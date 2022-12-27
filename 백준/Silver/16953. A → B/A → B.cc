#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ong;

int cnt = 50;
ong B;

void solution(ong a, int visit) {
	if (a == B) cnt = min(cnt, visit);
	else if (a > B) return;
	else if (a < B) {
		solution(a * 2, visit + 1);
		solution(a * 10 + 1, visit + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ong A;
	cin >> A >> B;

	solution(A, 1);
	if (cnt == 50) cout << -1;
	else cout << cnt;
	return 0;
}