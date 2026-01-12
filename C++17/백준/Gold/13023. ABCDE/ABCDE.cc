#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M, k = 1;
vector<vector<int>> graph;
vector<int> depth, stk;

bool dfs(int cur, int d) {
    if (d > 4) return true;
    stk[cur] = 1;

    bool ret = false;
    for (const int& next : graph[cur]) {
        if (stk[next]) continue;
        ret |= dfs(next, d + 1);
    }

    stk[cur] = 0;

    return ret;
}

void init() {
    cin >> N >> M;
    graph.resize(N);
    depth.resize(N);
    stk.resize(N);

    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void solve() {
    bool ans = false;
    for (int s = 0; !ans && s < N; ++s, ++k)
        ans |= dfs(s, 1);
    cout << (ans ? 1 : 0);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
