#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* merge sort tree + binary search
*/

int N;
vector<int> original;
vector<vector<int>> tree;

vector<int> init_tree(int s, int e, int cur) {
    if (s == e) return tree[cur] = vector<int>({ original[s - 1] });

    int mid = (s + e) / 2;
    vector<int> left = init_tree(s, mid, cur << 1);
    vector<int> right = init_tree(mid + 1, e, cur << 1 | 1);

    tree[cur].resize(e - s + 1);
    merge(left.begin(), left.end(), right.begin(), right.end(), tree[cur].begin());

    return tree[cur];
}

void init() {
    cin >> N;
    original.resize(N);
    tree.resize(N * 4 + 1);
    for (int& i : original) cin >> i;
    init_tree(1, N, 1);
}

int search(const int& k, const int& i, const int& j, int s, int e, int cur) {
    if (e < i || j < s) return 0;
    if (i <= s && e <= j)
        return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k);

    int mid = (s + e) / 2;
    int left = search(k, i, j, s, mid, cur << 1);
    int right = search(k, i, j, mid + 1, e, cur << 1 | 1);

    return left + right;
}

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << search(k, i, j, 1, N, 1) << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}