#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 각 문자들을 앞 문자들에 이어 붙여서 dp 구성
 * U -> UO -> UOS -> ... -> UOSPC
 */

int N;

string str;
ll cost[300'000];
vector<vector<ll>> dp;

void init(){
    cin >> N;
    dp.resize(5+1, vector<ll>(N+1, LLONG_MAX));
    fill(dp[0].begin(), dp[0].end(), 0);

    cin >> str;
    for(int i = 0; i < N; i++)
        cin >> cost[i];
}

void solve(){
    string ch = "UOSPC";
    for(int k = 1; k <= 5; k++){
        for(int i = 1; i <= N; i++){
            if(str[i - 1] != ch[k - 1] || (k > 1 && dp[k - 1][i] == LLONG_MAX))
                dp[k][i] = dp[k][i - 1];
            else
                dp[k][i] = min(dp[k - 1][i] + cost[i - 1], dp[k][i - 1]);
        }
    }

    cout << (dp[5][N] == LLONG_MAX ? -1 : dp[5][N]);
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
