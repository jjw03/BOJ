#include <bits/stdc++.h>
using namespace std;

/*
* 각 상태에서 2가지 경우가 있음
* 왼쪽 발을 움직이는 경우
* 오른쪽 발을 움직이는 경우
* 
* 또한 각 발의 위치를 기억해야하므로
* dp[i][j][k]: i번 지시 사항을 수행했을 때 왼발이 j번 발판, 오른발이 k번 발판에 있을 때 최솟값
*/

int calc_force(int from, int to) {
    if (from == to) return 1;
    if (from == 0) return 2;
    if ((from + to) % 2 == 0) return 4;
    return 3;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> vec;
    vec.reserve(1e5);
    int in;
    while (cin >> in) {
        if (in == 0) break;
        vec.push_back(in);
    }

    int n = vec.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(5, vector<int>(5, INT_MAX)));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int to = vec[i - 1];
        for (int left = 0; left < 5; left++) {
            for (int right = 0; right < 5; right++) {
                if (dp[i - 1][left][right] == INT_MAX) continue;    //undefined path

                //case 1: 왼발을 움직임
                dp[i][to][right] = min(dp[i][to][right], dp[i - 1][left][right] + calc_force(left, to));

                //case 2: 오른발을 움직임
                dp[i][left][to] = min(dp[i][left][to], dp[i - 1][left][right] + calc_force(right, to));
            }
        }
    }

    int ans = INT_MAX;
    for (int left = 0; left < 5; left++) {
        for (int right = 0; right < 5; right++) {
            ans = min(ans, dp[n][left][right]);
        }
    }

    cout << ans;

    return 0;
}