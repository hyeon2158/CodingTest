#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair <int, char> > fre(100);
	string str;
	cin >> str;

	transform(str.begin(), str.end(), str.begin(), ::toupper);

	for (size_t i = 0; i < str.size(); i++)
	{
		int a = str[i];
		fre[a].first++;
		fre[a].second = str[i];
	}

	sort(fre.begin(), fre.end());
	if (fre[99].first == fre[98].first) cout << '?';
	else cout << fre[99].second;
	return 0;
}