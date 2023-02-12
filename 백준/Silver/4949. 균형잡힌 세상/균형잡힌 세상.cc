#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100'001
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string a;
	getline(cin, a);
	while (a != ".") {
		stack<int> b;
		bool c = true;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] == '[' || a[i] == '(') b.push(a[i]);
			else if (a[i] == ')') {
				if (b.empty() || b.top() != '(') {
					c = 0;
					break;
				}
				else b.pop();
			}
			else if (a[i] == ']') {
				if (b.empty() || b.top() != '[') {
					c = 0;
					break;
				}
				else b.pop();
			}
		}
		if (b.empty() && c) {
			cout << "yes\n";
		}
		else cout << "no\n";
		getline(cin, a);
	}
	return 0;
}