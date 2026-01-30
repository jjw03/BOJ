#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M;
vector<vector<int>> graph;

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int bfs(int x, int y) {
    int ret = 1;

    queue<pair<int, int>> to_visit;
    to_visit.push({ x, y });
    graph[x][y] = 0;

    while (!to_visit.empty()) {
        auto [cx, cy] = to_visit.front();
        to_visit.pop();

        for (const auto& [dx, dy] : dir) {
            int nx = cx + dx, ny = cy + dy;

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
            if (graph[nx][ny] == 0) continue;

            ++ret;
            graph[nx][ny] = 0;
            to_visit.push({ nx, ny });
        }
    }

    return ret;
}

void init() {
    cin >> N >> M;

    graph.resize(N, vector<int>(M));

    for (auto& v : graph) {
        for (int& i : v) cin >> i;
    }
}

void solve() {
    int cnt = 0, ans = 0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < M; ++y) {
            if (graph[x][y]) {
                ++cnt;
                ans = max(ans, bfs(x, y));
            }
        }
    }

    cout << cnt << '\n' << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
