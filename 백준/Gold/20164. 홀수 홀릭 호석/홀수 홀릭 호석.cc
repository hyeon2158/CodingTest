#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int M = 0;
int m = 1'000'000;
void solution(string N, int sum) {
	int size = N.size();
	int n = stoi(N);
	while (n)
	{
		if (n % 2) sum++;
		n /= 10;
	}
	if (size == 1) {
		if (sum > M) M = sum;
		if (sum < m) m = sum;
		return;
	}
	else if (size == 2) {
		string a = N.substr(0, 1);
		string b = N.substr(1);
		int temp = stoi(a) + stoi(b);
		string num = to_string(temp);
		solution(num, sum);
	}
	else if (size >= 3) {
		for (size_t i = 1; i < size - 1; i++)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				string a = N.substr(0, i);
				string b = N.substr(i, j - i);
				string c = N.substr(j);
				int temp = stoi(a) + stoi(b) + stoi(c);
				string num = to_string(temp);
				solution(num, sum);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string N;
	cin >> N;
	int size = N.size();
	solution(N, 0);
	cout << m << ' ' << M;
	return 0;
}