#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> d;
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		string order;
		cin >> order;
		if (order == "push_front") {
			int enter;
			cin >> enter;
			d.push_front(enter);
		}
		if (order == "push_back") {
			int enter;
			cin >> enter;
			d.push_back(enter);
		}
		if (order == "pop_front") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		if (order == "pop_back") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		if (order == "size") {
			cout << d.size() << '\n';
		}
		if (order == "empty") {
			if (d.empty()) cout << "1\n";
			else cout << "0\n";
		}
		if (order == "front") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << '\n';
			}
		}
		if (order == "back") {
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << '\n';
			}
		}
	}
	return 0;
}