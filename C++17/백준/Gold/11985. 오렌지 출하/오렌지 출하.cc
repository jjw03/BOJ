#include <bits/stdc++.h>
#define FASTIO cin.tie(0), ios_base::sync_with_stdio(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* dp[i + k]: i번째 오렌지부터 시작하여 k개의 오렌지를 넣었을 때 최소 비용
*/

int main() {
    FASTIO;

    ll N, M, K;
    cin >> N >> M >> K;

    vector<ll> weight(N);
    for (ll& i : weight) cin >> i;

    vector<ll> dp(N + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        ll min_w = LLONG_MAX, max_w = 0;
        for (int cnt = 1; cnt <= M && i + cnt <= N; cnt++) {
            min_w = min(min_w, weight[i + cnt - 1]);
            max_w = max(max_w, weight[i + cnt - 1]);

            // cnt개만큼 넣었을때 비용 최소값은 i-1번째 결과 or 현재 오렌지에서 다시 넣는 결과를 비교
            dp[i + cnt] = min(dp[i + cnt], dp[i] + K + cnt * (max_w - min_w));
        }
    }

    cout << dp[N];

    return 0;
}