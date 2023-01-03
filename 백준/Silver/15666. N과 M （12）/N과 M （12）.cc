#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector <int> num;
//vector <bool> visit(8);

void graph(int curr, int cnt, queue<int> a) {
	a.push(num[curr]);
	if (cnt == M) {
		while (!a.empty()) {
			cout << a.front() << ' ';
			a.pop();
		}
		cout << '\n';
		return;
	}
	else {
		int b = 0;
		for (size_t i = curr; i < num.size(); i++)
		{
			if (b == num[i]) continue;
			b = num[i];
			graph(i, cnt + 1, a);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (size_t i = 0; i < N; i++)
	{
		int ent;
		cin >> ent;
		num.push_back(ent);
	}
	sort(num.begin(), num.end());
	for (size_t i = 0; i < N; i++)
	{
		queue<int> a;
		if (i != 0 && num[i] == num[i - 1]) continue;
		graph(i, 1, a);
	}
	return 0;
}