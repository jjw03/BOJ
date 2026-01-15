#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 투 포인터로 모든 조합 찾고 차이가 가장 큰 조합 출력
*/

void init() {
}

void solve() {
    int X;
    while (cin >> X) {
        int N;
        vector<int> piece;

        cin >> N;

        X *= (int)1e7;  // nm to cm

        piece.resize(N);
        for (int& i : piece) cin >> i;

        sort(piece.begin(), piece.end());   // ascending order

        pair<int, int> ans = { 0, 0 };
        int a = 0, b = N - 1;
        while (a < b) {
            int sum = piece[a] + piece[b];
            if (sum == X) {
                ans = { piece[a], piece[b] };
                break;
            }
            else if (sum > X) {
                --b;
            }
            else {
                ++a;
            }
        }

        if (ans.first == 0)
            cout << "danger";
        else
            cout << "yes " << ans.first << ' ' << ans.second;
        cout << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
