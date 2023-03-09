#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;


int main(void) {
	string N;
	int B;
	cin >> N >> B;
	
	int num = 0;
	int count = 1;
	for (int i = N.size() -1 ; i >= 0; i--)
	{
		if (N[i] <= '9') {
			num += (N[i] - '0') * count;
			count*= B;
		}
		else if (N[i] > '9') {
			num += (N[i] - 55) * count;
			count *= B;
		}
	}
	cout << num;
	return 0;
}