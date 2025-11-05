#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x;
    int y;
    int z;
    pos(int x, int y, int z) : x(x), y(y), z(z) {}
};

vector<pos> dir = {
    {-1, 0, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, -1},
    {0, 0, 1}
};

int BFS(const vector<vector<vector<int>>>& g, const vector<pos>& init_pos) {
    int height = g.size(), width = g.front().size(), length = g.front().front().size();
    auto is_valid = [&height, &width, &length](const pos& p) {
        return (0 <= p.x && p.x < height)
            && (0 <= p.y && p.y < width)
            && (0 <= p.z && p.z < length);
        };

    vector<vector<vector<int>>> visited(height, vector<vector<int>>(width, vector<int>(length, INT_MAX)));

    int ret = 0;

    queue<pair<pos, int>> to_visit;
    for (const pos& p : init_pos) {
        to_visit.push({ p, 0 });
        visited[p.x][p.y][p.z] = 0;
    }

    while (!to_visit.empty()) {
        const pos cur = to_visit.front().first;
        int val = to_visit.front().second;
        to_visit.pop();

        if (val > visited[cur.x][cur.y][cur.z]) continue;

        for (const pos& d : dir) {
            pos next = { cur.x + d.x, cur.y + d.y, cur.z + d.z };
            if (!is_valid(next)) continue;

            int next_val = visited[cur.x][cur.y][cur.z] + 1;
            if (g[next.x][next.y][next.z] == 0 && visited[next.x][next.y][next.z] > next_val) {
                visited[next.x][next.y][next.z] = next_val;
                to_visit.push({ next, next_val });
            }
        }
    }

    bool is_possible = true;
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            for (int z = 0; z < length; z++) {
                if (g[x][y][z] == 0 && visited[x][y][z] == INT_MAX)
                    is_possible = false;
                if (visited[x][y][z] != INT_MAX) 
                    ret = max(ret, visited[x][y][z]);
            }
        }
    }

    return (is_possible ? ret : -1);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> g(h, vector<vector<int>>(n, vector<int>(m)));
    vector<pos> init_pos;
    init_pos.reserve(1e6);

    int cnt_raw = 0, cnt_ripe = 0;
    for (int i = h - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            for (int k = m - 1; k >= 0; k--) {
                cin >> g[i][j][k];
                if (g[i][j][k] == 1) {
                    cnt_ripe++;
                    init_pos.push_back(pos(i, j, k));
                }
                else if (g[i][j][k] == 0) cnt_raw++;
            }
        }
    }

    if (cnt_raw == 0) 
        cout << 0;
    else {
        int ans = BFS(g, init_pos);
        cout << ans;
    }

    return 0;
}
