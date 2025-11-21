#include <bits/stdc++.h>
#define FASTIO cin.tie(0), ios_base::sync_with_stdio(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dp[101][101][101];

int main() {
    FASTIO;

    string A, B, C;
    cin >> A >> B >> C;

    int sz_a = A.size(), sz_b = B.size(), sz_c = C.size();
    for (int a = 1; a <= sz_a; a++) {
        for (int b = 1; b <= sz_b; b++) {
            for (int c = 1; c <= sz_c; c++) {
                if (A[a - 1] == C[c - 1] && B[b - 1] == C[c - 1]) {
                    dp[a][b][c] = dp[a - 1][b - 1][c - 1] + 1;
                }
                else {
                    dp[a][b][c] = max(dp[a - 1][b][c], max(dp[a][b - 1][c], dp[a][b][c - 1]));
                }
            }
        }
    }

    cout << dp[sz_a][sz_b][sz_c];

    return 0;
}