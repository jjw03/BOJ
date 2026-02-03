#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int w, h;
int graph[50][50];

vector<pair<int, int>> dir = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

inline bool in_bound(int x, int y) {
    return (0 <= x && x < h) && (0 <= y && y < w);
}

void bfs(int x, int y) {
    queue<pair<int, int>> to_visit;
    to_visit.push({ x, y });
    graph[x][y] = 0;

    while (!to_visit.empty()) {
        auto [cx, cy] = to_visit.front();
        to_visit.pop();

        for (const auto& [dx, dy] : dir) {
            int nx = cx + dx, ny = cy + dy;

            if (!in_bound(nx, ny) || graph[nx][ny] == 0) continue;

            graph[nx][ny] = 0;
            to_visit.push({ nx, ny });
        }
    }
}

void init() {
}

void solve() {
    while (cin >> w >> h) {
        if (w == 0) break;

        for (int i = h - 1; i >= 0; --i) {
            for (int k = w - 1; k >= 0; --k)
                cin >> graph[i][k];
        }

        int cnt = 0;

        for (int x = 0; x < h; ++x) {
            for (int y = 0; y < w; ++y) {
                if (graph[x][y]) {
                    ++cnt;
                    bfs(x, y);
                }
            }
        }

        cout << cnt << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
