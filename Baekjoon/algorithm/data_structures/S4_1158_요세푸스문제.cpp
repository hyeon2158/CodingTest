#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> jose;
	queue<int> seq;
	int N, K;
	cin >> N >> K;
	for (size_t i = 1; i <= N; i++)
	{
		jose.push(i);
	}
	cout << '<';
	for (size_t i = 0; i < N; i++)
	{
		int s = K;
		while (jose.size() < s) { s -= jose.size(); }
		for (size_t j = 0; j < s; j++)
		{
			seq.push(jose.front());
			jose.pop();
		}
		for (size_t j = 0; j < s - 1; j++)
		{
			jose.push(seq.front());
			seq.pop();
		}
		if (i != N - 1) {
			cout << seq.front() << ", ";
			seq.pop();
		}
	}
	cout << seq.front() << '>';
	return 0;
}