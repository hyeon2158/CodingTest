#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int N, C;
		cin >> N >> C;
		if (N % C) cout << N / C + 1 << endl;
		else cout << N / C << endl;
	}
	return 0;
}
