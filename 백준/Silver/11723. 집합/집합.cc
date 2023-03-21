#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> S(21);

	for (size_t i = 0; i < N; i++)
	{
		string ent;
		cin >> ent;
		if (ent == "add") {
			int x;
			cin >> x;
			S[x] = 1;
		}
		else if (ent == "remove") {
			int x;
			cin >> x;
			S[x] = 0;
		}
		else if (ent == "check") {
			int x;
			cin >> x;
			if (S[x]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (ent == "toggle") {
			int x;
			cin >> x;
			S[x] = S[x] ? 0 : 1;
		}
		else if (ent == "all") {
			for (size_t j = 1; j < 21; j++)
			{
				S[j] = 1;
			}
		}
		else if (ent == "empty") {
			for (size_t j = 1; j < 21; j++)
			{
				S[j] = 0;
			}
		}
	}
	return 0;
}
