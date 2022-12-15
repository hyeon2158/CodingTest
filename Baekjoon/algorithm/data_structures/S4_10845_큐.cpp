#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	int N;
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		string order;
		cin >> order;

		if (order == "push") {
			int ent;
			cin >> ent;
			q.push(ent);
		}
		if (order == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		if (order == "size") {
			cout << q.size() << '\n';
		}
		if (order == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << "0\n";
		}
		if (order == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		if (order == "back") {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}

	return 0;
}