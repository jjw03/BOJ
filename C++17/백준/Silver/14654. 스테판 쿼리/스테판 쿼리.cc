#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<int> A, B;

void init() {
    cin >> N;
    A.resize(N);
    B.resize(N);

    for (int& i : A) cin >> i;
    for (int& i : B) cin >> i;
}

// -1: draw, 0: a wins, 1: b wins
inline int winner(int a, int b) {
    if (a == b) return -1;
    return (b == (a % 3) + 1 ? 1 : 0);
}

void solve() {
    int ans = 1, t = 1;
    int cur_winner = winner(A[0],B[0]) ? 1 : 0; // 0: A, 1: B
    for (int i = 1; i < N; i++) {
        int w = winner(A[i], B[i]);
        if (w == -1) {
            ans = max(ans, t);
            t = 1;
            cur_winner ^= 1;
        }
        else {
            //winner changes
            if (cur_winner ^ w) {
                ans = max(ans, t);
                t = 1;
                cur_winner ^= 1;
            }
            else {
                t++;
            }
        }
    }

    cout << max(ans, t);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}