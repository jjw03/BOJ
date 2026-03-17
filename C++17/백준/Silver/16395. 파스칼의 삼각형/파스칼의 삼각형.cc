#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n, k;
ll dp[30][30];

void init(){
    cin >> n >> k;
}

void solve(){
    for(int i = 0; i < 30; ++i){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for(int row = 1; row < 30; ++row){
        for(int col = 1; col < row; ++col)
            dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
    }

    cout << dp[n - 1][k - 1];
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
