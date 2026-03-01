#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// 간단 dp

int N;
int dp[1000 + 1], leap[1000 + 1];

void init(){
    cin >> N;

    for(int i = 1; i <= N; ++i)
        cin >> leap[i];

    fill(dp, dp + 1001, 10000);
    dp[1] = 0;
}

void solve(){
    for(int cur = 1; cur <= N; ++cur){
        for(int d = 1; d <= leap[cur] && cur + d <= N; ++d)
            dp[cur + d] = min(dp[cur + d], dp[cur] + 1);
    }

    if(dp[N] > 1000) 
        cout << -1;
    else
        cout << dp[N];
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
