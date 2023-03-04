#include <iostream>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	bool SK = 1;

	while (N > 3) {
		N = N - 3;
		SK = SK ? 0 : 1;
	}
	if (SK == 1 && N == 3) cout << "CY";
	else if (SK == 1 && N == 2) cout << "SK";
	else if (SK == 1 && N == 1) cout << "CY";
	else if (SK == 0 && N == 3) cout << "SK";
	else if (SK == 0 && N == 2) cout << "CY";
	else if (SK == 0 && N == 1) cout << "SK";

	return 0;
}