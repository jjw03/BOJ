#include <bits/stdc++.h>
using namespace std;

/*
* 각 픽셀에서 만들어 질 수 있는 정사각형의 width, height는 다음과 같다
* width = min of (x-1, y-1) and (x, y-1)
* height = min of (x-1, y-1) and (x-1, y)
* 
*/

struct square {
    int height;
    int width;
    square(int height = 0, int width = 0) : width(width), height(height) {}
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        string in; cin >> in;
        for (int k = 1; k <= m; k++)
            vec[i][k] = (in[k - 1] == '1');
    }

    int ans = 0;
    vector<vector<square>> dp(n + 1, vector<square>(m + 1));
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (vec[x][y] == 0) continue;

            dp[x][y].height = min(dp[x - 1][y - 1].height, dp[x - 1][y].height) + 1;
            dp[x][y].width = min(dp[x - 1][y - 1].width, dp[x][y - 1].width) + 1;

            int length = min(dp[x][y].height, dp[x][y].width);
            ans = max(ans, length * length);
        }
    }

    cout << ans;

    return 0;
}