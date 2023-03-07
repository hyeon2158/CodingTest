#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<double> score;
	for (size_t i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		score.push_back(tmp);
	}
	sort(score.begin(), score.end());

	double M = score.back();
	double sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += score[i] / M * 100;
	}
	cout << sum / N;
	return 0;
}