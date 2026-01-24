#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, K;
set<pair<int, int>> piece;

vector<pair<int, int>> dir = {
    {-2, 0},
    {2, 0},
    {0, -2},
    {0, 2}
};

inline bool in_bound(int x, int y) {
    return (1 <= x && x <= N) && (1 <= y && y <= N);
}

void init() {
    cin >> N >> K;

    while (K--) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        piece.insert(p);
    }
}

void solve() {
    set<pair<int, int>> pos;
    for (auto iter = piece.begin(); iter != piece.end(); ++iter) {
        const auto& [x, y] = *iter;
        for (const auto& [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;

            if (in_bound(nx, ny) && piece.find({ nx, ny }) == piece.end())
                pos.insert({ nx, ny });
        }
    }

    cout << pos.size();
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
