#include <bits/stdc++.h>
using namespace std;

struct pos {
    int x;
    int y;
    pos(int x, int y) : x(x), y(y) {}
};

vector<pos> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int BFS(const vector<vector<int>>& g, const vector<pos>& start) {
    int row = g.size(), col = g.front().size();

    vector<vector<int>> visited(row, vector<int>(col, INT_MAX));
    queue<pair<pos, int>> to_visit;
    for (const pos& p : start) {
        to_visit.push({ p, 0 });
        visited[p.x][p.y] = 0;
    }

    while (!to_visit.empty()) {
        const pos cur = to_visit.front().first;
        int cost = to_visit.front().second;
        to_visit.pop();

        if (cost > visited[cur.x][cur.y]) continue;

        for (const pos& d : dir) {
            pos next = { cur.x + d.x, cur.y + d.y };
            if (next.x < 0 || row <= next.x || next.y < 0 || col <= next.y) continue;
            if (g[next.x][next.y] == -1) continue;

            int new_cost = visited[cur.x][cur.y] + 1;
            if (new_cost < visited[next.x][next.y]) {
                visited[next.x][next.y] = new_cost;
                to_visit.push({ next, new_cost });
            }
        }
    }

    bool is_possible = true;
    int ret = 0;
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < col; k++) {
            if (visited[i][k] != INT_MAX) {
                ret = max(ret, visited[i][k]);
            }
            if (g[i][k] == 0 && visited[i][k] == INT_MAX) {
                is_possible = false;
            }
        }
    }

    return is_possible ? ret : -1;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    int cnt_raw = 0;
    vector<vector<int>> g(n, vector<int>(m));
    vector<pos> start;
    for (vector<int>& v : g) {
        for (int& i : v) {
            cin >> i;
            if (i == 0) cnt_raw++;
            else if (i == 1) {
                start.push_back({ static_cast<int>(&v - &g[0]), static_cast<int>(&i - &v[0]) });
            }
        }
    }

    cout << BFS(g, start);

    return 0;
}
