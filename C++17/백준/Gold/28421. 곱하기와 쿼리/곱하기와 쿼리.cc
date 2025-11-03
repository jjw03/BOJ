#include <bits/stdc++.h>
using namespace std;

/*
* 수열에 속하는 수의 범위는 최대 1만이므로
* 각 수가 몇개 존재하는지 세어서 쿼리에 활용한다
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<int> seq(N), cnt(1e4 + 1, 0);
    for (int& i : seq) {
        cin >> i;
        cnt[i]++;
    }

    while (Q--) {
        int q, x;
        cin >> q >> x;
        if (q == 1) {
            int result = 0;
            if (N == 1) {
                result = 0;
            }
            else if (x == 0) {
                result = (cnt[0] > 0);
            }
            else {
                int n;
                for (n = 1; n * n < x && result == 0; n++) {
                    if (x % n == 0 && x / n <= 1e4) {
                        result = (cnt[n] > 0 && cnt[x / n] > 0);
                    }
                }
                if (n * n == x && result == 0) result = (cnt[n] > 1);
            }
            cout << result << '\n';
        }
        else {
            if (seq[x - 1] != 0) {
                cnt[seq[x - 1]]--;
                cnt[0]++;
                seq[x - 1] = 0;
            }
        }
    }

    return 0;
}
