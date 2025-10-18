#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;

	for (int i = n - 5; i < n; i++)
		cout << s[i];

	return 0;
}