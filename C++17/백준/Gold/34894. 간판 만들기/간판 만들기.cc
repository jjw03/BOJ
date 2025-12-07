#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 1차원 dp
 * U -> UO -> ... -> UOSPC
 */

int N;

string str;
int cost[300'000];
vector<ll> dp;

void init(){
    cin >> N;
    dp.resize(N + 1, LLONG_MAX);

    cin >> str;
    for(int i = 0; i < N; i++){
        cin >> cost[i];
        if(str[i] == 'U')    //dp 초기화
            dp[i + 1] = 0;
    }
}

void solve(){
    string ch = "UOSPC";
    for(int k = 1; k <= 5; k++){
        for(int i = 1; i <= N; i++){
            //이어 붙일 수 없는 위치 or 이전 문자가 등장하지 않았음
            if(str[i - 1] != ch[k - 1] || dp[i] == LLONG_MAX)
                dp[i] = dp[i - 1];
            //이어 붙일 수 있는 위치
            else
                dp[i] = min(dp[i] + cost[i - 1], dp[i - 1]);
        }
    }

    cout << (dp[N] == LLONG_MAX ? -1 : dp[N]);
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
