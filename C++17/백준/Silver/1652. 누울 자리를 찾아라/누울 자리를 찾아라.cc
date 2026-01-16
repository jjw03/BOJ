#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// 가로, 세로 따로 한번씩 탐색

int N;
vector<vector<int>> _map;

void init() {
    cin >> N;
    _map.resize(N, vector<int>(N));
    for (auto& v : _map) {
        string s;
        cin >> s;
        for (int i = 0; i < N; ++i)
            v[i] = (s[i] != 'X');
    }
}

void solve() {
    int cnt_horizontal = 0, cnt_vertical = 0;
    // horizontal
    for (const auto& v : _map) {
        bool set = true;
        for (int i = 1; i < N; ++i) {
            if (!set && !v[i]) {
                set = true;
                continue;
            }
            if (!set) continue;
            if (v[i] && v[i - 1]) {
                ++cnt_horizontal;
                set = false;
            }
        }
    }

    // vertical
    for (int col = 0; col < N; ++col) {
        bool set = true;
        for (int row = 1; row < N; ++row) {
            if (!set && !_map[row][col]) {
                set = true;
                continue;
            }
            if (!set) continue;
            if (_map[row][col] && _map[row - 1][col]) {
                ++cnt_vertical;
                set = false;
            }
        }
    }

    cout << cnt_horizontal << ' ' << cnt_vertical;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
