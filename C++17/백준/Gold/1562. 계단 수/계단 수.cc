#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int divisor = 1'000'000'000;
int N;
ull memo[1 << 10][100 + 1][10];    // i개의 숫자를 가지고 j번째 자리에 k가 등장하는 경우의 수

ull dp(int last_digit, int mask, int sz){
    if(sz == N) return memo[mask][N][last_digit] = (mask == (1 << 10) - 1) ? 1 : 0;
    if(memo[mask][sz][last_digit] != 0) return memo[mask][sz][last_digit];
    
    ull ret = 0;
    if(last_digit - 1 >= 0)
        ret = dp(last_digit - 1, mask | (1 << (last_digit - 1)), sz + 1) % divisor;
    if(last_digit + 1 <= 9)
        ret = (ret + dp(last_digit + 1, mask | (1 << (last_digit + 1)), sz + 1) % divisor) % divisor;
    return memo[mask][sz][last_digit] = ret;
}

void init(){
    cin >> N;
}

void solve(){
    if(N < 10) {
        cout << 0;
        return;
    }
    
    ull ans = 0;
    for(int i = 1; i <= 9; ++i)
        ans = (ans % divisor + dp(i, 1 << i, 1) % divisor) % divisor;
    cout << ans;
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
