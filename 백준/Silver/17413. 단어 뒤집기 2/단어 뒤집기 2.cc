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

	string str;
	getline(cin,str);
	int index = 0;
	int blank = str.find(' ');
	int left = str.find('<');
	int right = str.find('>');

	string nstr;
	while (blank != -1 || left != -1) {
		string cpy;
		if (left == string::npos || ( blank != string::npos && blank < left)) {
			cpy = str.substr(index, blank-index);
			reverse(cpy.begin(), cpy.end());
			nstr += cpy;
			nstr += ' ';
			index = blank + 1;
		}
		else if (blank == string::npos || blank > left){
			cpy = str.substr(index, left-index);
			reverse(cpy.begin(), cpy.end());
			nstr += cpy;
			cpy = str.substr(left, right - left + 1);
			nstr += cpy;
			index = right + 1;
		}
		blank = str.find(' ', index);
		left = str.find('<', index);
		right = str.find('>', index);
	}
	string end = str.substr(index);
	reverse(end.begin(), end.end());
	cout << nstr << end;
	return 0;
}