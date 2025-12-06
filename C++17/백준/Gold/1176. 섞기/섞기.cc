#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * i번째 학생을 배치할 때 이전에 어떤 학생들이 배치되었는지 비트마스킹으로 저장한다
 * 2^16 = 약 65000
 * O(N*2^16)
 */

int N, K, lim = 0;

ll memo[(1 << 16) + 1][16];
vector<int> height;

void init(){
    cin >> N >> K;
    height.resize(N);
    for(int& i : height) cin >> i;

    for(int i = 0; i < N; i++)
        lim |= (1 << i);
}

ll calc_dp(int bit_mask, int i){
    if(bit_mask == lim) return memo[bit_mask][i] = 1;
    if(memo[bit_mask][i] != 0) return memo[bit_mask][i];

    ll ret = 0;
    for(int b = N - 1; b >= 0; b--){
        //이미 배치한 수
        if(bit_mask & (1 << b)) continue;
        //다음에 배치하려는 수와의 차이가 K를 넘지 못함
        if(abs(height[b] - height[i]) <= K) continue;

        ret += calc_dp(bit_mask | (1 << b), b);
    }

    return memo[bit_mask][i] = ret;
}

void solve(){
    ll ans = 0;
    for(int b = N - 1; b >= 0; b--)
        ans += calc_dp(1 << b, b);
    cout << ans;
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
