#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

bool prime(int const Num) {
	for (int i = 2; i <= sqrt(Num); i++)
	{
		if (Num % i == 0)
		{
			return false;;
		}
	}
	return true;
}



bool decode(int const Num) {
	string Str = to_string(Num);
	string Str_Cpy = Str;
	reverse(Str_Cpy.begin(), Str_Cpy.end());
	return Str == Str_Cpy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int StartNum = 0;
	int EndNum = 0;

	cin >> StartNum >> EndNum;
	for (int i = StartNum; i <= EndNum; i++)
	{
		if (i > 10000000)
			break;
		if (decode(i) && prime(i))
			cout << i << "\n";
	}

	cout << -1;
	return 0;
}