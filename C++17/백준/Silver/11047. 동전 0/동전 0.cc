#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* A_i는 A_i-1의 배수이므로 그리디 알고리즘으로 가능
*/

int N, K;
vector<int> coin;

void init() {
    cin >> N >> K;
    coin.resize(N);
    for (int& i : coin) cin >> i;
}

void solve() {
    int ans = 0;
    int idx = N - 1;
    while (K > 0 && idx >= 0) {
        if (coin[idx] <= K) {
            ans += K / coin[idx];
            K %= coin[idx];
        }
        idx--;
    }
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}