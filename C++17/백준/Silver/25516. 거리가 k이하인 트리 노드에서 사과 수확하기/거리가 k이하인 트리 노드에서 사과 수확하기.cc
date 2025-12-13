#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, k;
vector<vector<int>> tree;
vector<int> apple, visited;

void init() {
    cin >> n >> k;
    tree.resize(n);
    apple.resize(n);
    visited.resize(n);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
    }

    for (int& i : apple) cin >> i;
}

int DFS(int cur = 0, int d = 0) {
    if (d > k) return 0;
    visited[cur] = 1;

    int ret = apple[cur];
    for (const int& next : tree[cur]) {
        if (visited[next]) continue;
        ret += DFS(next, d + 1);
    }

    return ret;
}

void solve() {
    cout << DFS();
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}