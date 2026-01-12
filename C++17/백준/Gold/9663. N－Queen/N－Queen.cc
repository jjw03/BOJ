#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
int col[15];
vector<pair<int, int>> queens;

bool is_valid(int r, int c) {
    bool ret = true;
    for (const auto& [pr, pc] : queens) {
        if (abs(pr - r) == abs(pc - c)) {
            ret = false;
            break;
        }
    }
    return ret;
}

int backtracking(int r) {
    if (queens.size() == N) return 1;

    int ret = 0;
    for (int nc = 0; nc < N; ++nc) {
        if (col[nc] || !is_valid(r + 1, nc)) continue;

        col[nc] = 1;
        queens.push_back({ r + 1, nc });
        
        ret += backtracking(r + 1);
        
        col[nc] = 0;
        queens.pop_back();
    }

    return ret;
}

void init() {
    cin >> N;
    queens.reserve(15);
}

void solve() {
    cout << backtracking(-1);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
