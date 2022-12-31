#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
 
typedef long long ong;
int main(void) {
	int N;
	cin >> N;
	vector<vector <ong> > num(N+1, vector<ong>(2, 0));
	
	num[1][1] = 1;
	if (N >= 2) num[2][0] = 1;

	for (size_t i = 3; i <= N; i++)
	{
		num[i][1] = num[i - 1][0];
		num[i][0] = num[i - 1][0] + num[i - 1][1];
	}

	cout << num[N][0] + num[N][1];
	return 0;
}