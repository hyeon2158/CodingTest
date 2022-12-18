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

	vector <int> height;
	int sum = 0;

	for (size_t i = 0; i < 9; i++)
	{
		int ent;
		cin >> ent;
		height.push_back(ent);
		sum += ent;
	}
	sort(height.begin(), height.end());

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = i; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100) {
				for (size_t k = 0; k < 9; k++)
				{
					if (k != i && k != j) {
						cout << height[k] << '\n';
					}
				}
				return 0;
			}
		}
	}
}