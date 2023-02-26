#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, fre = 0;
	cin >> n >> num;

	for (size_t i = 1; i <= n; i++)
	{
		string temp = to_string(i); 
		for (size_t j = 0; j < temp.length(); j++)
		{
			if (temp[j] == num + '0') {
				fre++;
			}
		}
	}
	cout << fre;
	return 0;
}