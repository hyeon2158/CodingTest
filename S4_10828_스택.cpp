#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	stack<int> stk;
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		string order;
		cin >> order;
		if (order == "push") {
			int element;
			cin >> element;
			stk.push(element);
		}
		else if (order == "pop") {
			if (stk.empty()) cout << -1 << '\n';
			else { cout << stk.top() << '\n';  stk.pop(); }
		}
		else if (order == "size") {
			cout << stk.size() << '\n';
		}
		else if (order == "empty") {
			if (stk.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (order == "top") {
			if (stk.empty()) cout << -1 << '\n';
			else cout << stk.top() << '\n';
		}
	}
	return 0;
}