#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M;
vector<pair<int, int>> point;

void init() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < M; ++k) {
            int in;
            cin >> in;
            if (in)
                point.push_back({ i, k });
        }
    }
}

void solve() {
    const auto& [x1, y1] = point[0];
    const auto& [x2, y2] = point[1];
    cout << abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
