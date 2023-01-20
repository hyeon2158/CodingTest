#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int P;
	cin >> P;
	int score = 0;
	for (size_t i = 0; i < P; i++)
	{
		char ent;
		cin >> ent;
		score += ent - 64;
	}
	cout << score;
}