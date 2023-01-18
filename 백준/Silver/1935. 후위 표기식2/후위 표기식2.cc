#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//queue<int> num;
	int num[101]{};
	int N;
	cin >> N;

	string equation;

	cin >> equation;
	int count = 0;
	for (size_t i = 0; i < equation.size(); i++)
	{
		if (count != N && num[i] == 0 && equation[i] != '+' && equation[i] != '-' && equation[i] != '*' && equation[i] != '/') {
			int enter;
			cin >> enter;
			num[i] = enter;
			for (size_t j = i + 1; j < equation.size(); j++)
			{
				if (equation[i] == equation[j]) num[j] = num[i];
			}
			count++;
		}
	}
	deque<double> a;

	for (size_t i = 0; i < equation.size(); i++)
	{
		if (equation[i] == '+') {
			double b = a.back();
			a.pop_back();
			double c = a.back();
			a.pop_back();
			a.push_back(c + b);
		}
		else if (equation[i] == '-') {
			double b = a.back();
			a.pop_back();
			double c = a.back();
			a.pop_back();
			a.push_back(c - b);
		}
		else if (equation[i] == '*') {
			double b = a.back();
			a.pop_back();
			double c = a.back();
			a.pop_back();
			a.push_back(c * b);
		}
		else if (equation[i] == '/') {
			double b = a.back();
			a.pop_back();
			double c = a.back();
			a.pop_back();
			a.push_back(c / b);
		}
		else {
			a.push_back(num[i]);
		}
	}
	cout << setprecision(2) << fixed << a.front();
	return 0;
}
