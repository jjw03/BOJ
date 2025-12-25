#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M, key = 1;
vector<int> visited;
vector<vector<pair<int, int>>> edge;

void init() {
    cin >> N >> M;

    edge.resize(N);
    visited.resize(N);

    for (int i = 1; i < N; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a - 1].push_back({ b - 1, w });
        edge[b - 1].push_back({ a - 1, w });
    }
}

pair<ull, bool> dist(const int& node, int cur) {
    visited[cur] = key;
    if (node == cur) return { 0, true };

    ull ret = 0;
    for (const auto& [next, w] : edge[cur]) {
        if (visited[next] == key) continue;

        auto [d, isFound] = dist(node, next);
        if (isFound)
            ret = d + w;
    }

    return { ret, ret > 0 };
}

void solve() {
    while (M--) {
        int p, q;
        cin >> p >> q;
        cout << dist(p - 1, q - 1).first << '\n';
        key++;
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}