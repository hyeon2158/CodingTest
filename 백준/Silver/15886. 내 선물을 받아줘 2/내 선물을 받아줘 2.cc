#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string map;
	int N;
	int present = 0;
	cin >> N;
	cin >> map;
	for (size_t i = 1; i < map.length(); i++)
	{
		if (map[i] == 'W' && map[i - 1] == 'E') {
			present++;
		}
	}
	if (!present) cout << 1;
	else cout << present;
	return 0;
}