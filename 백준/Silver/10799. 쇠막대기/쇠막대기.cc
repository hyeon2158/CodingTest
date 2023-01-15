#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> block;
	string stick;
	cin >> stick;
	int count = 0;
	for (size_t i = 0; i < stick.size(); i++)
	{
		if (stick[i] == '(' && stick[i + 1] == ')') {
			count += block.size();
		}
		else if (stick[i] == '(' && stick[i + 1] != ')') {
			block.push(1);
		}
		else if (stick[i] == ')' && stick[i-1] != '(') {
			block.pop();
			count++;
		}
	}
	cout << count;
	return 0;
}
