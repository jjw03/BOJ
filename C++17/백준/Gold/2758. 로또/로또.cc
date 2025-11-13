#include <bits/stdc++.h>
using namespace std;

/*
* top-down
* 메모이제이션의 값 초기화 주의
* https://djm03178.tistory.com/38
*/

vector<vector<long long>> memo;

//cnt번째 숫자로 num을 고르는 경우의 수
long long dp(int cnt, int num) {
    if (memo[cnt][num] != -1) return memo[cnt][num];
    if (cnt == 1) return memo[cnt][num] = 1;

    long long ret = 0;
    for (int n = num / 2; n >= 1; n--)
        ret += dp(cnt - 1, n);

    return memo[cnt][num] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    memo.resize(10 + 1, vector<long long>(2000 + 1, -1));

    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;

        long long ans = 0;
        for (int i = 1; i <= m; i++)
            ans += dp(n, i);
        cout << ans << '\n';
    }

    return 0;
}