#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M, R;
vector<int> order;
vector<vector<int>> graph;

void bfs() {
    int o = 1;
    order[R - 1] = o++;

    queue<int> to_visit;
    to_visit.push(R - 1);

    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();

        for (const int& next : graph[cur]) {
            if (order[next] == 0) {
                order[next] = o++;
                to_visit.push(next);
            }
        }
    }
}

void init() {
    cin >> N >> M >> R;

    order.resize(N);
    graph.resize(N);

    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    for (auto& v : graph)
        sort(v.begin(), v.end());
}

void solve() {
    bfs();
    for (const int& i : order)
        cout << i << '\n';
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
