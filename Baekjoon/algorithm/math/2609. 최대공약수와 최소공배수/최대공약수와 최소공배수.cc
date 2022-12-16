#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;

	cin >> m >> n;
	
	int greatest = 1;
	int least = m*n;

	//최대공약수
	if (m >= n) {
		for (size_t i = 1; i <= n; i++)
		{
			if (m%i == 0 && n%i ==0) greatest = i;
		}
	}
	if (m < n) {
		for (size_t i = 1; i <= m; i++)
		{
			if (m%i == 0 && n%i == 0) greatest = i;
		}
	}
	least = least / greatest;
	cout << greatest << "\n" << least;
}
