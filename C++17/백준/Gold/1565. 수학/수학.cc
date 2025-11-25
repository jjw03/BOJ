#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int d, m;
ll D[51], M[51];

void init() {
    cin >> d >> m;
    for (int i = 0; i < d; i++)
        cin >> D[i];
    for (int i = 0; i < m; i++)
        cin >> M[i];
}

ll find_lcm() {
    ll ret = D[0];
    for (int i = 1; i < d; i++)
        ret = lcm(ret, D[i]);
    return ret;
}

ll find_gcd() {
    ll ret = M[0];
    for (int i = 1; i < m; i++)
        ret = gcd(ret, M[i]);
    return ret;
}

int main() {
    FAST_IO;

    init();

    ll _lcm = find_lcm(), _gcd = find_gcd();
    
    vector<ll> divisor;
    for (ll i = 1; i * i <= _gcd; i++) {
        if (_gcd % i == 0)  {
            divisor.push_back(i);
            if(_gcd / i != i)
                divisor.push_back(_gcd / i);
        }
    }

    int ans = 0;
    for (const ll& i : divisor) {
        if (i < _lcm) continue;
        if (i % _lcm == 0) ans++;
    }

    cout << ans;

    return 0;
}
