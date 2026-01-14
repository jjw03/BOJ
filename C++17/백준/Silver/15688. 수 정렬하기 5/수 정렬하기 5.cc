#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int offset = 1e6;
int N;
int num[2 * offset + 1];

void init() {
    cin >> N;
}

void solve() {
    while (N--) {
        int a;
        cin >> a;
        ++num[a + offset];
    }

    for (int i = 0; i <= offset * 2; ++i) {
        while (num[i]--)
            cout << i - offset << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
