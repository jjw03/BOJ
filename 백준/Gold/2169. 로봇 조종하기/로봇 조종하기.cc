#include <bits/stdc++.h>
using namespace std;

/*
* 좀 tricky한 문제
* 
* 항상 하던대로 배열 순회를 왼->오 방향으로 하는데
* 이럴 경우 위->아래, 왼->오 방향으로 들어가는 루트의 경우에는 상태전이에 문제가 없음
* 그런데 오->왼 방향의 상태전이는 연속적인 움직임을 반영할 수가 없음
* 그럼 어떻게 하냐?
* 순회는 왼->오 그대로 하되, 오->왼 방향의 상태를 전이할 수 있도록 대칭적인 인덱스를 구하는 거임
* 팰린드롬 느낌 생각하면 쉬움
* 
* 각 위치에서 위 -> 아래 방향과 오->왼or왼->오 방향 중 최댓값을 구하면 됨
*/

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> val(n, vector<int>(m));
    for (vector<int>& v : val) {
        for (int& i : v) cin >> i;
    }

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = val[0][0];
    for (int i = 1; i < m; i++) //첫 라인은 오른쪽으로만 이동 가능
        dp[0][i] = dp[0][i - 1] + val[0][i];

    for (int i = 1; i < n; i++) {
        //0: left -> right, 1: right -> left
        vector<vector<int>> temp(2, vector<int>(m, INT_MIN));

        // boundary 미리 올리기
        temp[0][0] = dp[i - 1][0] + val[i][0];
        temp[1][m - 1] = dp[i - 1][m - 1] + val[i][m - 1];

        for (int to_right = 1; to_right < m; to_right++) {
            int to_left = m - 1 - to_right; // to_right + to_left = m - 1

            temp[0][to_right] = max(dp[i - 1][to_right], temp[0][to_right - 1]) + val[i][to_right];
            temp[1][to_left] = max(dp[i - 1][to_left], temp[1][to_left + 1]) + val[i][to_left];
        }

        for (int k = 0; k < m; k++)
            dp[i][k] = max(temp[0][k], temp[1][k]);
    }

    cout << dp[n - 1][m - 1];

    return 0;
}