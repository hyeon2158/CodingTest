#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	cin.ignore();

	for (size_t i = 0; i < T; i++)
	{
		string TD;
		stack<char> bracket;
		getline(cin, TD);
		int decode = 1;
		for (size_t j = 0; j < TD.size(); j++)
		{
			if (bracket.empty() && TD[j] == '(') {
				bracket.push('(');
			}
			else if (bracket.empty() && TD[j] == ')') {
				cout << "NO\n";
				decode = 0;
				break;
			}
			else if (!bracket.empty() && TD[j] == '(') {
				bracket.push('(');
			}
			else if (!bracket.empty() && TD[j] == ')') {
				bracket.pop();
			}
		}
		if (decode && bracket.empty()) cout << "YES\n";
		else if (decode && !bracket.empty()) cout << "NO\n";

	}
	return 0;
}