#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int black(string a[], int b, int c) {
	int uncorrect = 0;
	int decode = 1;
	for (size_t i = b; i < b+8; i++)
	{
		for (size_t j = c; j < c+8; j++)
		{
			if (decode) {
				if (a[i][j] == 'W') {
					uncorrect++;
				}
				decode = 0;
			}
			else if (decode != 1) {
				if (a[i][j] == 'B') {
					uncorrect++;
				}
				decode = 1;
			}
		}
		decode = (decode ? 0 : 1);
	}
	return uncorrect;
}

int white(string a[], int b, int c) {
	int uncorrect = 0;
	int decode = 1;
	for (size_t i = b; i < b+8; i++)
	{
		for (size_t j = c; j < c+8; j++)
		{
			if (decode) {
				if (a[i][j] == 'B') {
					uncorrect++;
				}
				decode = 0;
			}
			else if (decode != 1) {
				if (a[i][j] == 'W') {
					uncorrect++;
				}
				decode = 1;
			}
		}
		decode = (decode ? 0 : 1);
	}
	return uncorrect;
}

int main() {
	int M, N;
	cin >> M >> N;
	int uncorrect = 64;

	string a[50];

	for (size_t i = 0; i < M; i++)
	{
		cin >> a[i];
	}
	int count = 0;
	for (size_t i = 0; i <= M - 8; i++)
	{
		
		for (size_t j = 0; j <= N - 8; j++)
		{
			count = (black(a, i, j) >= white(a, i, j)) ? white(a, i, j) : black(a, i, j);
			if (count < uncorrect) {
				uncorrect = count;
			}
		}
	}
	cout << uncorrect;
}