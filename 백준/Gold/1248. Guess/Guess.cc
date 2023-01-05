#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef unsigned long long ong;

int n;
vector<vector <char> > sign(10, vector<char>(10));
//bool decode = 1;

//default cnt = 0, curr = null, sum = 0, num = i
void DFS(int cnt, vector<int> curr, vector<int> sum, int num) { 
	//if (!decode) return;
	if (cnt == n) {
		//decode = 0;
        for (size_t i = 0; i < n; i++)
	{
		cout << curr[i] << ' ';
	}
		exit(0);
	}
	if (sign[cnt][cnt] == '+')
	{
		curr.push_back(num);
	}
	if (sign[cnt][cnt] == '-')
	{
		curr.push_back(num*(-1));
	}
	if (sign[cnt][cnt] == '0')
	{
		curr.push_back(0);
	}
	sum.push_back(sum.back()+curr.back());
	for (size_t i = 0; i < cnt; i++)
	{
		if (sign[i][cnt] == '+') {
			if (sum[cnt+1] - sum[i] <= 0) {
				return;
			}
		}
		if (sign[i][cnt] == '-') {
			if (sum[cnt+1] - sum[i] >= 0) {
				return;
			}
		}
		if (sign[i][cnt] == '0') {
			if (sum[cnt+1] - sum[i] != 0) {
				return;
			}
		}
	}
	for (size_t i = 1; i <= 10; i++)
	{
		DFS(cnt + 1, curr, sum, i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			cin >> sign[i][j];
		}
	}
	for (size_t i = 1; i <= 10; i++)
	{
		vector<int> curr;
		vector<int> sum(1);
		DFS(0, curr, sum , i);
	}
	return 0;
}