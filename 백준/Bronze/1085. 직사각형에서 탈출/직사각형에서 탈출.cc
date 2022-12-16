#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	int min;
	cin >> x >> y >> w >> h;
	min = abs(x - w) <= abs(y - h) ? x - w : y - h;
	if (abs(min) > x) min = x;
	if (abs(min) > y) min = y;
	cout << abs(min);
}