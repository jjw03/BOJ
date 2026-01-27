#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;

void init() {
    cin >> N;
}

void solve() {
    int cnt = 0;
    for (int comp = N ^ (~N + 1), shift = 0; shift < 32; ++shift) {
        if (comp & (1 << shift))
            ++cnt;
    }
    cout << cnt;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
