#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long a, b;
	cin >> a >> b;
	cout << a * b / __gcd(a, b);

	return 0;
}