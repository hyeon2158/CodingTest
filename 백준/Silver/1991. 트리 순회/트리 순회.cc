#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>

#define MAX 100'001
using namespace std;
vector<char> tree[26];
void preorder(char curr) {
	if (curr == '.') return;
	cout << curr;
	preorder(tree[curr - 'A'][0]);
	preorder(tree[curr - 'A'][1]);
}
void inorder(char curr) {
	if (curr == '.') return;
	inorder(tree[curr - 'A'][0]);
	cout << curr;
	inorder(tree[curr - 'A'][1]);
}
void postorder(char curr) {
	if (curr == '.') return;
	postorder(tree[curr - 'A'][0]);
	postorder(tree[curr - 'A'][1]);
	cout << curr;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].push_back(b);
		tree[a - 'A'].push_back(c);
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	
	return 0;
}