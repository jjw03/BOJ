#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;

        //dp i k : i번째 숫자를 택할때 k를 고르는 경우의 수
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        dp[0][0] = 1;

        for (int cnt = 1; cnt <= n; cnt++) {
            for (int num = 1; num <= m; num++) {
                for (int i = num / 2; i >= 0; i--) {
                    dp[cnt][num] += dp[cnt - 1][i];
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= m; i++)
            ans += dp[n][i];
        cout << ans << '\n';
    }

    return 0;
}