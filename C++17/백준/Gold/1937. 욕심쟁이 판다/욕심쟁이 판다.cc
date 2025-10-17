#include <bits/stdc++.h>
using namespace std;

/*
* 임의의 타일에서 이동할 수 있는 최대값이 존재할 것이고 이 값은 전역 최적해의 부분 최적해가 된다
* 따라서 각 타일에서 최대 이동값을 구하고 각 타일에 대해 최대값을 구해주면 답이된다
*/

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

struct pos {
    int x;
    int y;
    pos(int x, int y) : x(x), y(y) {}
};

int n;
vector<vector<int>> cnt, _map;

int dp(const pos cur, const int prv_val) {
    if ((cur.x < 0 || n <= cur.x) || (cur.y < 0 || n <= cur.y))
        return 0;
    if (_map[cur.x][cur.y] <= prv_val) return 0;
    
    if (cnt[cur.x][cur.y] != 0) return cnt[cur.x][cur.y];

    int ret = 0;
    for (const pair<int, int>& d : dir)
        ret = max(ret, dp(pos(cur.x + d.first, cur.y + d.second), _map[cur.x][cur.y]));

    return cnt[cur.x][cur.y] = ret + 1;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    cnt.resize(n, vector<int>(n, 0));
    _map.resize(n, vector<int>(n));
    for (vector<int>& v : _map) {
        for (int& i : v) cin >> i;
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++)
            dp(pos(x, y), 0);
    }
    
    int ans = 0;
    for (const vector<int>& v : cnt) {
        for (const int i : v) ans = max(ans, i);
    }

    cout << ans;

    return 0;
}