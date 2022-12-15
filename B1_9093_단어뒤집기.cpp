#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		vector<string> TC;
		string ent;
		int f = 1;
		while (f || cin.peek() != '\n') {
			cin >> ent;
			reverse(ent.begin(), ent.end());
			TC.push_back(ent);
			f = 0;
		}
		for (size_t i = 0; i < TC.size() - 1; i++)
		{
			cout << TC[i] << ' ';
		}
		cout << TC.back() << '\n';
	}
	return 0;
}