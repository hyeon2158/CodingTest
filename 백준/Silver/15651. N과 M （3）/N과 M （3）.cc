#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector <int> num;
//vector <bool> visit(9);

void graph(int curr, int cnt, queue<int> a) {
	a.push(curr);
	if (cnt == M) {
		while (!a.empty()) {
			cout << a.front() << ' ';
			a.pop();
		}
		cout << '\n';
		return;
	 }
	else {
		for (size_t i = 1; i <= num.size(); i++)
		{
			//if (visit[i] == true) continue;
			//visit[i] = true;
			graph(i, cnt + 1, a);
			//visit[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (size_t i = 1; i <= N; i++)
	{
		num.push_back(i);
	}
	for (size_t i = 1; i <= N; i++)
	{
		queue<int> a;
	//	visit[i] = true;
		graph(i, 1, a);
	//	visit[i] = false;
	}
	return 0;
}