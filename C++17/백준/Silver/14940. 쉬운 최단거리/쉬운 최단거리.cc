#include <bits/stdc++.h>
using namespace std;

/*
* 간단한 BFS 문제
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> g[i][k];
            if (g[i][k] == 2) start = { i, k };
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[start.first][start.second] = 0;
    
    queue<pair<int, int>> to_visit;
    to_visit.push(start);
    
    vector<pair<int, int>> dir = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    while (!to_visit.empty()) {
        const auto [x, y] = to_visit.front();
        to_visit.pop();

        for (const auto& [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if (g[nx][ny] == 0) continue;

            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                to_visit.push({ nx, ny });
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (dist[x][y] != INT_MAX) cout << dist[x][y] << ' ';
            else cout << (g[x][y] == 0) - 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}