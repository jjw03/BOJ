#include <bits/stdc++.h>
using namespace std;

/*
* top down dp
*/

int memo[70][70][70];

vector<vector<int>> order = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

vector<int> weight = {
    9, 3, 1
};

int dp(int a, int b, int c) {
    if (a <= 0 && b <= 0 && c <= 0) return 0;

    //각 scv hp는 음수가 될 수 있으므로 clamp
    a = max(a, 0), b = max(b, 0), c = max(c, 0);
    if (memo[a][b][c] != 0) return memo[a][b][c];

    //모든 조합 탐색
    int ret = 1e3;
    for (const vector<int>& o : order) {
        ret = min(ret, dp(a - weight[o[0]], b - weight[o[1]], c - weight[o[2]]));
    }

    return memo[a][b][c] = ret + 1;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> scv(3);
    for (int i = 0; i < N; i++) cin >> scv[i];

    cout << dp(scv[0], scv[1], scv[2]);

    return 0;
}
