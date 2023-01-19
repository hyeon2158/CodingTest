#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string front;
	cin >> front;
	stack<char> stk;

	for (size_t i = 0; i < front.size(); i++)
	{
		if (front[i] >= 65 && front[i] <= 90) {
			cout << front[i];
		}
		else if (front[i] == '+' || front[i] == '-') {
			while (!stk.empty() && stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.push(front[i]);
		}
		else if (front[i] == '*' || front[i] == '/') {
			while (!stk.empty() && stk.top() != '(' && stk.top() != '+' && stk.top() != '-') {
				cout << stk.top();
				stk.pop();
			}
			stk.push(front[i]);
		}
		else if (front[i] == '(') {
			stk.push('(');
		}
		else if (front[i] == ')') {
			while (stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
	}
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
	return 0;
}
