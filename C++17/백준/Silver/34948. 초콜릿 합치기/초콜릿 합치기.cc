#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
ll width[200'000 + 1];

void init() {
    cin >> N;
    vector<int> h(N);
    for (int& i : h) cin >> i;

    for (int i = 0; i < N; i++) {
        int w; cin >> w;
        width[h[i]] += w;
    }
}

void solve() {
    ll ans = 0;
    ll summation_width = 0;

    for (ll h = 200'000; h >= 1; h--) {
        if (width[h] == 0) continue;
        summation_width += width[h];
        ans = max(ans, summation_width * h);
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}