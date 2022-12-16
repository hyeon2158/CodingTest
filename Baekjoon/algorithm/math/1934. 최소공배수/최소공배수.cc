#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <numeric>


using namespace std;

//int gcd(int a, int b) {
//	int small = a > b ? b : a;
//	int gcd = 1;
//	for (size_t i = 2; i <= small; i++)
//	{
//		if (a%i == 0 && b%i == 0) gcd = i;
//	}
//	return gcd;
//}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int a, b;
	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
}