#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
int board[100][100];
ll dp[100][100];

inline bool in_bound(int x, int y) {
    return (0 <= x < N) && (0 <= y < N);
}

void init() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            cin >> board[i][k];
        }
    }

    dp[0][0] = 1;
}

void solve() {
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (x == N - 1 && y == N - 1) break;

            if (in_bound(x + board[x][y], y))
                dp[x + board[x][y]][y] += dp[x][y];

            if (in_bound(x, y + board[x][y]))
                dp[x][y + board[x][y]] += dp[x][y];
        }
    }

    cout << dp[N - 1][N - 1];
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
