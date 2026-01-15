#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, from, to;
vector<vector<int>> graph;
vector<int> dist;

void bfs() {
    queue<int> to_visit;
    to_visit.push(from - 1);
    dist[from - 1] = 0;

    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();

        for (const int& next : graph[cur]) {
            int nd = dist[cur] + 1;
            if (dist[next] == -1 || nd < dist[next]) {
                dist[next] = nd;
                to_visit.push(next);
            }
        }
    }
}

void init() {
    cin >> n >> from >> to;
    graph.resize(n);
    dist.resize(n, -1);

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
}

void solve() {
    bfs();
    cout << dist[to - 1];
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
