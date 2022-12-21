#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main(void) {
	int N;
	cin >> N;
	vector<string> word;

	for (size_t i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		word.push_back(str);
	}
	//sort(word.begin(), word.end());
	sort(word.begin(), word.end(), compare);
	word.erase(unique(word.begin(), word.end()),word.end());

	//sort(word.begin(), word.end(), compare);

	for (size_t i = 0; i < word.size(); i++)
	{
		cout << word[i] << endl;
	}
	return 0;
}