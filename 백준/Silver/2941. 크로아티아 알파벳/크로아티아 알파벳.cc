#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100'001
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string cro;
	cin >> cro;
	int cnt = 0;
	for (size_t i = 0; i < cro.size(); i++)
	{
		if (cro[i] == '=' && cro[i - 1] == 'z') continue;
		else if (i > 0 && i < cro.size() && cro[i + 1] == '=' && cro[i] == 'z' && cro[i-1] == 'd') continue;
		else if (cro[i] == '=' && cro[i - 1] == 's') continue;
		else if (cro[i] == '=' && cro[i - 1] == 'c') continue;
		else if (i > 0 && cro[i] == 'j' && cro[i - 1] == 'n') continue;
		else if (i > 0 && cro[i] == 'j' && cro[i - 1] == 'l') continue;
		else if (cro[i] == '-' && cro[i - 1] == 'd') continue;
		else if (cro[i] == '-' && cro[i - 1] == 'c') continue;
		cnt++;
	}
	cout << cnt;
	return 0;
}