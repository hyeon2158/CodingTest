#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	queue<int> card;
	cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		card.push(i);
	}
	while (card.size() != 1) {
		cout << card.front() << ' ';
		card.pop();
		card.push(card.front());
		card.pop();
	}
	cout << card.front();
	return 0;
}