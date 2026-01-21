#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 각 사각형의 왼쪽 위 꼭짓점을 pivot으로 설정
* 4개의 변을 따라서 '*'을 그려넣음
*/

int N, length;
vector<vector<char>> vec;

vector<pair<int, int>> dir = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

void init() {
    cin >> N;
    length = 1 + 4 * (N - 1);
    vec.resize(length + 1, vector<char>(length + 1, ' '));
}

void solve() {
    int x = 1, y = 1, tl = length;
    while (tl >= 1) {
        vec[x][y] = '*';

        // 4개 변 marking
        int tx = x, ty = y;
        for (const auto& [dx, dy] : dir) {
            for (int tll = tl; tll > 1; --tll) {
                vec[tx][ty] = '*';
                tx += dx, ty += dy;
            }
        }

        // pivot, length update
        x += 2, y += 2;
        tl -= 4;
    }

    for (int i = 1; i <= length; ++i) {
        for (int k = 1; k <= length; ++k)
            cout << vec[i][k];
        cout << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
