#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_SIZE 50
using namespace std;

int N, L, R;
bool visit[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
vector<vector<int> > map;
vector <pair<int, int>> v;

//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0, -1 };

bool decode(string word) {
	bool aeiou = 0;
	int cnt = 0;
	int aeioucnt = 0;
	int bcdcnt = 0;
	for (size_t i = 0; i < word.length(); i++)
	{
		if (word[i] != 'e' && word[i] != 'o' && i != 0 && word[i] == word[i - 1]) {
			return false;
		}
		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
			aeiou = true;
			aeioucnt++;
			bcdcnt = 0;
			if (aeioucnt == 3) return false;
		}
		else {
			bcdcnt++;
			aeioucnt = 0;
			if (bcdcnt == 3) return false;
		}
	}
	if (aeiou) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	cin >> word;
	while (word != "end") {
		if (decode(word)) cout << '<' << word << '>' << " is acceptable.\n";
		else cout << '<' << word << '>' << " is not acceptable.\n";
		cin >> word;
	}
	return 0;
}