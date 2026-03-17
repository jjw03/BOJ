#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M, K;
int dp[15][15];
pair<int, int> via = {0, 0};

void path(pair<int, int> s, pair<int, int> e){
    if(s == e) return;

    for(int row = s.first; row <= e.first; ++row){
        for(int col = s.second; col <= e.second; ++col){
            if(row == s.first && col == s.second) continue;
            
            if(s.first <= row - 1) dp[row][col] += dp[row - 1][col];
            if(s.second <= col - 1) dp[row][col] += dp[row][col - 1];
        }
    }
}

void init(){
    cin >> N >> M >> K;
    
    dp[0][0] = 1;

    if(K != 0){
        if(K % M == 0)
            via = {K / M - 1, M - 1};
        else
            via = {K / M, K % M - 1};
    }
}

void solve(){
    path({0, 0}, via);
    path(via, {N - 1, M - 1});

    cout << dp[N - 1][M - 1];
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
