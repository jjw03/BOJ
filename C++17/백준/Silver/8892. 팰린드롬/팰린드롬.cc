#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int K;
		cin >> K;
		vector<string> vec(K);
		for (string& s : vec) cin >> s;
		string ans = "0";
		for (int i = 0; i < K; i++) {
			for (int k = 0; k < K; k++) {
				if (i == k) continue;
				string m1 = vec[i] + vec[k], m2 = vec[k] + vec[i];
				bool ispal_1 = true, ispal_2 = true;
				int a = 0, b = vec[i].size() + vec[k].size() - 1;
				while (a <= b) {
					if (m1[a] != m1[b]) ispal_1 = false;
					if (m2[a] != m2[b]) ispal_2 = false;
					a++, b--;
 				}
				if (ispal_1) ans = m1;
				else if (ispal_2) ans = m2;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}