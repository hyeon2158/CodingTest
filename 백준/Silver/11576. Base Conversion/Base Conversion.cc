#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

void conversion(int num, int cip) {
	if(num/cip) {
		conversion(num / cip, cip);
		cout << num % cip << ' ';
	}
	else cout << num << ' ';
}

int main(void) {
	int A, B;
	int m;
	cin >> A >> B >> m;

	int cip = m - 1;
    int num_10 = 0;

	for (size_t i = 0; i < m; i++)
	{
		int num_A;
		cin >> num_A;

		num_10 += pow(A, cip) * num_A;
		cip--;
	}
	conversion(num_10, B);

	return 0;
}