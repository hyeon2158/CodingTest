#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		char name;
		cin >> name;
		sum += name - 'A' + 1;
	}
	cout << sum;
	return 0;
}