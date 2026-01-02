#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M;
int isExist[1000 + 1];

void init() {
    cin >> N >> M;

    while (M--) {
        int n; cin >> n;
        isExist[n] = 1;
    }
}

void solve() {
    int ans = 0;
    for (int n = N; n > 0; n--) {
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0 && (isExist[d] || isExist[n / d])) {
                ans += n; 
                break;
            }
        }
    }
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}