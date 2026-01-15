#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<vector<int>> _map;

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
    _map[x][y] = 0;

    while (!to_visit.empty()) {
        auto [cx, cy] = to_visit.front();
        to_visit.pop();

        for (const auto& [wx, wy] : dir) {
            int nx = cx + wx, ny = cy + wy;
            if (nx < 0 || N <= nx || ny < 0 || N <= ny)
                continue;
            if (_map[nx][ny]) {
                _map[nx][ny] = 0;
                ++ret;
                to_visit.push({ nx, ny });
            }
        }
    }

    return ret;
}

void init() {
    cin >> N;
    _map.resize(N, vector<int>(N));
    for (auto& v : _map) {
        string s;
        cin >> s;
        for (int i = 0; i < N; ++i)
            v[i] = (s[i] == '1');
    }
}

void solve() {
    int total = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (_map[x][y]) {
                pq.push(bfs(x, y));
            }
        }
    }

    cout << pq.size() << '\n';
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
