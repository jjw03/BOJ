#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M;
int arr[2000][2000];
int calc[2000][2000];

void init() {
    cin >> N >> M;

    for (int x = 0; x < N; x++) {
        string s;
        cin >> s;
        for (int y = 0; y < M - 1; y++) {
            arr[x][y] = s[y] - '0';
        }
    }
}

vector<pair<int, int>> dir = {
    {-1, 1},
    {0, 1},
    {1, 1}
};

inline bool in_bound(int x, int y) {
    return (0 <= x && x < N) && (0 <= y && y < M);
}

int solve() {
    for (int col = 0; col < M; col++) {
        for (int row = 0; row < N; row++) {
            calc[row][col] += arr[row][col];

            for (const auto& [dx, dy] : dir) {
                int nx = row + dx, ny = col + dy;
                if (!in_bound(nx, ny)) continue;

                calc[nx][ny] = max(calc[nx][ny], calc[row][col]);
            }
        }
    }

    int ret = 0;
    for (int x = 0; x < N; x++)
    {
        ret = max(ret, calc[x][M - 1]);
    }
    return ret;
}

int main() {
    FAST_IO;

    init();
    cout << solve();

    return 0;
}
