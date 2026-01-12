#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool is_end = false;
int N, movement = 0, endpoint;
vector<pair<int, int>> tree;

void inorder(int cur = 0) {
    const auto& [left, right] = tree[cur];
    if (left >= 0) inorder(left);
    endpoint = cur;
    if (right >= 0) inorder(right);
}

void pseudo_inorder(int cur = 0) {
    const auto& [left, right] = tree[cur];

    if (left >= 0) {
        ++movement;
        pseudo_inorder(left);
        if (!is_end) ++movement;
    }

    if (right >= 0) {
        ++movement;
        pseudo_inorder(right);
        if (!is_end) ++movement;
    }

    if (cur == endpoint)
        is_end = true;
}

void init() {
    cin >> N;
    tree.resize(N);

    for (int i = N; i > 0; --i) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a - 1] = { b - 1, c - 1 };
    }
}

void solve() {
    inorder();
    pseudo_inorder();
    cout << movement;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
