#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int w, h;
int graph[1000][1000];

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};

inline bool in_bound(int x, int y) {
    return (0 <= x && x < h) && (0 <= y && y < w);
}

void bfs_fire(const vector<pair<int, int>>& start) {
    queue<pair<int, int>> to_visit;

    for (const auto p : start) {
        to_visit.push(p);
        graph[p.first][p.second] = 0;
    }

    while (!to_visit.empty()) {
        auto [x, y] = to_visit.front();
        to_visit.pop();

        for (const auto& [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;

            if (!in_bound(nx, ny) || graph[nx][ny] == -1) continue;

            if (graph[nx][ny] > graph[x][y] + 1) {
                graph[nx][ny] = graph[x][y] + 1;
                to_visit.push({ nx, ny });
            }
        }
    }
}

int bfs_escape(const pair<int, int>& start) {
    vector<vector<int>> graph_escape(h, vector<int>(w, INT_MAX));
    queue<pair<int, int>> to_visit;
    to_visit.push(start);
    graph_escape[start.first][start.second] = 0;

    while (!to_visit.empty()) {
        auto [x, y] = to_visit.front();
        to_visit.pop();

        for (const auto& [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;

            if (!in_bound(nx, ny) || graph[nx][ny] == -1) continue;

            if (graph[nx][ny] > graph_escape[x][y] + 1 && graph_escape[nx][ny] > graph_escape[x][y] + 1) {
                graph_escape[nx][ny] = graph_escape[x][y] + 1;
                to_visit.push({ nx ,ny });
            }
        }
    }

    int ret = INT_MAX;
    for (int i = 0; i < w; ++i) {
        ret = min(ret, graph_escape[0][i]);
        ret = min(ret, graph_escape[h - 1][i]);
    }
    for (int i = 0; i < h; ++i) {
        ret = min(ret, graph_escape[i][0]);
        ret = min(ret, graph_escape[i][w - 1]);
    }

    return ret != INT_MAX ? ret + 1 : -1;
}

void init() {
}

void solve() {
    int tt;
    cin >> tt;
    while (tt--) {        
        cin >> w >> h;

        pair<int, int> start;
        vector<pair<int, int>> fire;

        for (int i = 0; i < h; ++i) {
            string s;
            cin >> s;
            for (int k = 0; k < w; ++k) {
                if (s[k] == '#')
                    graph[i][k] = -1;
                else {
                    if (s[k] == '*') {
                        fire.push_back({ i, k });
                    }
                    else if (s[k] == '@') {
                        start = { i, k };
                    }
                    graph[i][k] = INT_MAX;
                }
            }
        }


        bfs_fire(fire);

        int ret = bfs_escape(start);
        if (ret == -1)
            cout << "IMPOSSIBLE";
        else
            cout << ret;
        cout << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
