#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> seq;
	stack<int> stk;
	stack<int> NGE;
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int enter;
		cin >> enter;
		seq.push_back(enter);
	}
	for (size_t i = 0; i < N; i++)
	{
		while (!stk.empty())
		{
			if (seq.back() < stk.top()) {
				NGE.push(stk.top());
				break;
			}
			else if (seq.back() >= stk.top()) {
				stk.pop();
			}
		}
		if (stk.empty()) NGE.push(-1);
		stk.push(seq.back());
		seq.pop_back();
	}
	for (size_t i = 0; i < N; i++)
	{
		cout << NGE.top() << ' ';
		NGE.pop();
	}
	//for (size_t i = 0; i < N; i++)
	//{
	//	for (size_t j = i+1; j < N; j++)
	//	{
	//		if (seq[i] < seq[j]) {
	//			NGE.push_back(seq[j]);
	//			break;
	//		}
	//		else if (j == N - 1) {
	//			NGE.push_back(-1);
	//		}
	//	}
	//}

	//for (size_t i = 0; i < N; i++)
	//{
	//	cout << NGE[i] << ' ';
	//}
	return 0;
}