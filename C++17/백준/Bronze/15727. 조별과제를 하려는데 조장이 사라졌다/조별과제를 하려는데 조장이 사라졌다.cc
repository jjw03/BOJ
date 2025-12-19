#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int L;

void init() {
    cin >> L;
}

void solve() {
    cout << (L / 5 + (L % 5 > 0));
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}