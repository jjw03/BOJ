#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M;
int is_available[10];

void init() {
    cin >> N >> M;
    fill(is_available, is_available + 10, 1);
    while (M--) {
        int in; cin >> in;
        is_available[in] = 0;
    }
}

void solve() {
    int ans = abs(100 - N);

    if (is_available[0])
        ans = min(ans, 1 + N);

    for (int num = N; 0 < num; --num) {
        int cnt = 0, t = num;
        while (t > 0) {
            if (!is_available[t % 10]) {
                cnt = 1e7;
                break;
            }
            ++cnt;
            t /= 10;
        }
        ans = min(ans, cnt + abs(N - num));
    }

    for (int num = N + 1; num <= max(100, 2 * N); ++num) {
        int cnt = 0, t = num;
        while (t > 0) {
            if (!is_available[t % 10]) {
                cnt = 1e7;
                break;
            }
            ++cnt;
            t /= 10;
        }
        ans = min(ans, cnt + abs(N - num));
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
