#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int fre[1000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> num;
	vector<pair<int, int> > seq;
	stack<pair<int, int> > stk;
	stack<pair<int, int> > NGF;
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int enter;
		cin >> enter;
		fre[enter]++;
		num.push_back(enter);
	}
	for (size_t i = 0; i < N; i++)
	{
		int a = num[i];
		int b = fre[num[i]];

		seq.push_back(pair<int, int>(b, a));
	}
	for (size_t i = 0; i < N; i++)
	{
		while (!stk.empty())
		{
			if (seq.back().first < stk.top().first) {
				NGF.push(stk.top());
				break;
			}
			else if (seq.back().first >= stk.top().first) {
				stk.pop();
			}
		}
		if (stk.empty()) NGF.push(pair<int, int>(0, -1));
		stk.push(seq.back());
		seq.pop_back();
	}
	for (size_t i = 0; i < N; i++)
	{
		cout << NGF.top().second << ' ';
		NGF.pop();
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