#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> K;
	
	vector<int> book;
	int sum = 0;
	for (size_t i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		if (num) { 
			book.push_back(num);
			sum += num;
		}
		else {
			sum -= book.back();
			book.pop_back();
		}
	}
	cout << sum;
	return 0;
}