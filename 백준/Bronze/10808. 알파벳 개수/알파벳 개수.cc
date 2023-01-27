#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;


//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string front;
//	cin >> front;
//	string frontcpy(front);
//	deque<int> back;
//
//	for (size_t i = 0; i < front.size(); i++)
//	{
//		if (front[i] >= 65 || front[i] <= 90) {
//			back.push_back(front[i]);
//			if (front[i-1])
//		}  
//	}
//
//	int index = 0;
//	int current = front.find(index, '(');
//	for (size_t i = 0; i < front.size(); i++)
//	{
//		if()
//	}
//
//	return 0;
//}
int main(void) {
	int alpha[26]{};
	string word;

	cin >> word;

	for (size_t i = 0; i < word.size(); i++)
	{
		alpha[word[i]-97]++;
	}
	for (size_t i = 0; i < 26; i++)
	{
		cout << alpha[i] << ' ';
	}
	return 0;
}