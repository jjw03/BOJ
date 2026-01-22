#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, white = 0, blue = 0;
vector<vector<int>> board;

void divide(int x, int y, int length) {
    if (length == 1) {
        if (board[x][y])
            ++blue;
        else
            ++white;
        return;
    }

    // check
    int cnt = 0;
    for (int dx = 0; dx < length; ++dx) {
        for (int dy = 0; dy < length; ++dy) {
            cnt += board[x + dx][y + dy];
        }
    }

    if (cnt == 0) {
        ++white;
        return;
    }
    else if (cnt == length * length) {
        ++blue;
        return;
    }

    // rescursive
    int nl = length / 2;
    divide(x, y, nl);
    divide(x + nl, y, nl);
    divide(x, y + nl, nl);
    divide(x + nl, y + nl, nl);
}

void init() {
    cin >> N;

    board.resize(N, vector<int>(N));

    for (auto& v : board) {
        for (int& i : v) cin >> i;
    }
}

void solve() {
    divide(0, 0, N);
    cout << white << '\n' << blue;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
