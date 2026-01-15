#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, m, cnt = 0;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int cur = 0) {
    visited[cur] = 1;
    ++cnt;

    for (const int& next : graph[cur]) {
        if (!visited[next])
            dfs(next);
    }
}

void init() {
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
}

void solve() {
    dfs();
    cout << cnt - 1;    // 1번 컴 제외
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
