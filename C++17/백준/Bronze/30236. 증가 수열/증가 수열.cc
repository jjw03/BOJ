#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int tt, n;
int A[101];

void init() {
    cin >> tt;
}

void solve() {
    while (tt--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        int b = 1, idx_a = 0;
        while (idx_a < n) {
            // 서로 다르면 다음 숫자로 넘어감
            if (A[idx_a] != b) {
                ++b;
                ++idx_a;
            }
            // 서로 같으면 b를 증가시킴
            else {
                ++b;
            }
        }

        cout << b - 1 << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}