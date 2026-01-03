#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int MAX_SIZE = 100'000;
int N, Q;
ll tree[MAX_SIZE * 4 + 1];
ll leaf_idx[MAX_SIZE + 1], original[MAX_SIZE + 1];

ll init_tree(int s, int e, int cur) {
    if (s == e) {
        leaf_idx[s] = cur;
        return tree[cur] = original[s];
    }

    int mid = (s + e) / 2;
    ll left = init_tree(s, mid, cur << 1);
    ll right = init_tree(mid + 1, e, cur << 1 | 1);

    return tree[cur] = left + right;
}

void init() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> original[i];
    init_tree(1, N, 1);
}

void update(int pos, ll x){
    ll org = original[pos];
    original[pos] = x;
    for (ll idx = leaf_idx[pos]; idx > 0; idx >>= 1) {
        tree[idx] = tree[idx] - org + x;
    }
}

ll query(const int& l, const int& r, int s, int e, int cur) {
    if (e < l || r < s)
        return 0;
    if (l <= s && e <= r)
        return tree[cur];

    int mid = (s + e) / 2;
    ll left = query(l, r, s, mid, cur << 1);
    ll right = query(l, r, mid + 1, e, cur << 1 | 1);

    return left + right;
}

void solve() {
    while (Q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int p = min(x, y), q = max(x, y);
        cout << query(p, q, 1, N, 1) << '\n';
        update(a, b);
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}