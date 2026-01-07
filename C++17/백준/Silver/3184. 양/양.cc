#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int wall = -1, wolf = -2, sheep = -3;
int R, C;
int graph[250][250];    // -2: wolf, -3: sheep
vector<int> cnt_wolf, cnt_sheep;

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void init() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        string s; cin >> s;
        for (int k = 0; k < C; k++) {
            if (s[k] == '#')
                graph[i][k] = wall;
            else if (s[k] == 'v')
                graph[i][k] = wolf;
            else if (s[k] == 'o')
                graph[i][k] = sheep;
            else
                graph[i][k] = 0;
        }
    }
}

inline bool in_bound(int r, int c) {
    return (0 <= r && r < R) && (0 <= c && c < C);
}

void BFS(const pair<int, int> s) {
    queue<pair<int, int>> to_visit;
    to_visit.push(s);

    int cw = (graph[s.first][s.second] == wolf),
        cs = (graph[s.first][s.second] == sheep);

    graph[s.first][s.second] = 1;

    while (!to_visit.empty()) {
        auto [x, y] = to_visit.front();
        to_visit.pop();

        for (const auto& [wx, wy] : dir) {
            int nx = x + wx, ny = y + wy;
            if (!in_bound(nx, ny) 
                || graph[nx][ny] == wall
                || graph[nx][ny] == 1) continue;
            if (graph[nx][ny] == wolf)
                ++cw;
            else if (graph[nx][ny] == sheep)
                ++cs;

            graph[nx][ny] = 1;
            to_visit.push({ nx, ny });
        }
    }

    cnt_wolf.push_back(cw);
    cnt_sheep.push_back(cs);
}

void solve() {
    int mark = 1;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (graph[r][c] != -1 && graph[r][c] <= 0)
                BFS({ r, c });
        }
    }

    int w = 0, s = 0;
    for (int i = 0; i < cnt_wolf.size(); ++i) {
        if (cnt_sheep[i] <= cnt_wolf[i])
            w += cnt_wolf[i];
        else
            s += cnt_sheep[i];
    }

    cout << s << ' ' << w;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
