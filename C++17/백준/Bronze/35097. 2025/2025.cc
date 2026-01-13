#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void init() {
}

void solve() {
    int n;
    while(cin >> n) {
        if (n == 0) break;
        int ans = 0;
        for (int num = 1; num <= n; ++num) {
            for (int mul = 1; mul <= n; ++mul)
                ans += num * mul;
        }
        cout << ans << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
