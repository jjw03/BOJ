#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 그림은 한번만 살 수 있고, 산 가격보다 적게는 팔 수 없다는 것은
 * 순서 정보를 저장해야한다는 뜻이다
 * -> top-down dp로 해결
 */

int N, lim = 0;

int price[15][15];

// set에 해당하는 사람들을 지나고 i번째 사람이 구매했을 때 가격 k에 대한 dp값
int memo[1 << 15][15][10];

void init(){
    cin >> N;

    for(int i = N - 1; i >= 0; i--)
        lim |= (1 << i);

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int k = 0; k < N; k++)
            price[i][k] = s[k] - '0';
    }
}

int dp(int bit_mask = 1, int cur = 0, int cur_price = 0){
    if(bit_mask == lim) return N;
    if(memo[bit_mask][cur][cur_price] != 0) return memo[bit_mask][cur][cur_price];

    int ret = __builtin_popcount(bit_mask);
    for(int i = N - 1; i >= 0; i--){
        if(bit_mask & (1 << i)) continue;
        if(price[cur][i] < cur_price) continue;
        
        ret = max(ret, dp(bit_mask | (1 << i), i, price[cur][i]));
    }

    return memo[bit_mask][cur][cur_price] = ret;
}

void solve(){
    cout << dp();
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
