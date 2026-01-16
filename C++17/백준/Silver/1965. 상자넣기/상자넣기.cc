#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* O(N^2) DP
*/

int N;
int sz[1001], dp[1001];

void init() {
    cin >> N;
    fill(dp, dp + 1000, 1);
    for (int i = 1; i <= N; ++i)
        cin >> sz[i];
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k < i; ++k) {
            if (sz[i] > sz[k])
                dp[i] = max(dp[i], dp[k] + 1);
        }
    }
    
    int ans = 0;
    for (int i : dp)
        ans = max(ans, i);
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
