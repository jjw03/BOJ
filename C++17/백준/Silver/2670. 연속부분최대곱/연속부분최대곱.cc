#include <bits/stdc++.h>
using namespace std;

/*
* DP
* 각 값을 선택 / 선택하지 않은 경우를 구성하여 최적해를 구함
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<double> num(N);
    for (double& i : num) cin >> i;

    //0: 미선택, 1: 선택
    vector<vector<double>> dp(2, vector<double>(N + 1));

    for (int i = 1; i <= N; i++) {
        //선택하지 않는 경우: 이전까지의 최적해를 그대로 유지
        dp[0][i] = fmax(dp[0][i - 1], dp[1][i - 1]);
        //선택하는 경우: 이전까지 연속된 구간에 병합 또는 이전 구간 버리기
        dp[1][i] = fmax(num[i - 1], dp[1][i - 1] * num[i - 1]);
    }

    cout.precision(3);
    cout << fixed << fmax(dp[0].back(), dp[1].back());

    return 0;
}
