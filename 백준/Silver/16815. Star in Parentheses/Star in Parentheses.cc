#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	stack<int> stk;
	cin >> s;
	int cnt = 0;
	bool decode = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '*') decode = 1;
		else if (decode) {
			if (s[i] == ')') {
				if (!stk.empty()) {
					cnt++;
					stk.pop();
				}
			}
		}
		else {
			if (stk.empty()) {
				if (s[i] == '(') stk.push(s[i]); 
			}
			else {
				if (s[i] == '(') stk.push(s[i]);
				else stk.pop();
			}
		
		}
		
	}
	cout << cnt;
	return 0;
}