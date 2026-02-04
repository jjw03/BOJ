#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> dist;

void bfs() {
    queue<int> to_visit;
    to_visit.push(0);
    dist[0] = 0;

    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();

        if (dist[cur] >= 2) continue;

        for (const int& next : graph[cur]) {
            int d = dist[cur] + 1;
            
            if (dist[next] > d) {
                dist[next] = d;
                to_visit.push(next);
            }
        }
    }
}

void init() {
    cin >> n >> m;

    graph.resize(n);
    dist.resize(n, INT_MAX);

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
}

void solve() {
    bfs();
    int cnt = 0;
    for (const int& d : dist) {
        if (d <= 2) ++cnt;
    }
    cout << cnt - 1;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
