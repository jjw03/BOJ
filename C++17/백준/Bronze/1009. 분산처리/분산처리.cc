#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 답은 a^b mod 10 ==> 1의 자리 숫자
* 
* 거듭제곱 logN 버전
*/

int power(int num, int exponent) {
    if (exponent == 1) {
        return num % 10;
    }

    int ret = power(num, exponent / 2);
    ret = ((ret % 10) * (ret % 10)) % 10;

    if (exponent % 2 == 1)
        ret = (ret * (num % 10)) % 10;

    return ret;
}

void init() {
}

void solve() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;

        int ret = power(a, b);
        cout << (ret > 0 ? ret : 10) << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
