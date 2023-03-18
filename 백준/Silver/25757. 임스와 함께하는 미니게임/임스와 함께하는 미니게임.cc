#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	char game;
	cin >> N;
	cin >> game;
	vector<string> name;
	name.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> name[i];
	}
	sort(name.begin(), name.end());
	int cnt = N;
	for (size_t i = 0; i < N-1; i++)
	{
		if (name[i] == name[i + 1]) cnt--;
	}
	if (game == 'Y') cout << cnt;
	else if (game == 'F') cout << cnt / 2;
	else cout << cnt / 3;
	return 0;
}