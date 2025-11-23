#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    int ans = 0;
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;

        int t = 0;
        if (a == b && b == c) {
            t = 10000 + a * 1000;
        }
        else if (a != b && b != c && c != a) {
            t = max(a, max(b, c)) * 100;
        }
        else {
            t = 1000 + (a == b ? a : (b == c ? b : c)) * 100;
        }

        ans = max(ans, t);
    }

    cout << ans;

    return 0;
}