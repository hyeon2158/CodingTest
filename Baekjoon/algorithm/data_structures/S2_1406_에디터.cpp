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

	stack<char> left;
	stack<char> right;
	int M;

	while (cin.peek() != '\n')
	{
		char ent;
		cin >> ent;
		left.push(ent);
	}

	cin >> M;

	for (size_t i = 0; i < M; i++)
	{
		char order;
		cin >> order;
		if (order == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		if (order == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		if (order == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		if (order == 'P') {
			char ent;
			cin >> ent;
			left.push(ent);
		}
	}
	int ls = left.size();
	int rs = right.size();
	string str = "";
	for (size_t i = 0; i < ls; i++)
	{
		str += left.top();
		left.pop();
	}
	reverse(str.begin(), str.end());
	cout << str;
	for (size_t i = 0; i < rs; i++)
	{
		cout << right.top();
		right.pop();
	}
	return 0;
}