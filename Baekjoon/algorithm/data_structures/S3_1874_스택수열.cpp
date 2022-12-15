#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector <int> seq;
	string pp;


	int decode = 1;
	int count = 1;
	for (size_t i = 0; i < n; i++)
	{
		int enter;
		cin >> enter;
		if (seq.empty() || enter > seq.back()) {
			while (count - 1 != enter) {
				seq.push_back(count);
				pp += "+\n";
				count++;
			}
			seq.pop_back();
			pp += "-\n";
		}
		else if (enter <= seq.back()) {
			if (seq.back() != enter) { decode = 0; }
			else {
				seq.pop_back(); pp += "-\n";
			}
		}
	}
	if (decode == 0) {
		cout << "NO"; return 0;
	}
	cout << pp;
	return 0;
}