#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m;
	while (cin >> n >> m) {
		if (n == 0) break;

		vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= m; k++) {
				int in; cin >> in;
				if (in == 1) dp[i][k] = { 1, 1 };
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= m; k++) {
				if (dp[i][k].first == 0 && dp[i][k].second == 0) continue;
				dp[i][k].first = min(dp[i - 1][k].first, dp[i - 1][k - 1].first) + 1;
				dp[i][k].second = min(dp[i][k - 1].second, dp[i - 1][k - 1].second) + 1;

				if (dp[i][k].first == dp[i][k].second)
					ans = max(ans, dp[i][k].first);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}