#include <bits/stdc++.h>
using namespace std;

/*
* 슬라이딩 윈도우
*/

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> price(N);
        for (int& i : price) cin >> i;

        int cur_price = 0;
        int a = 0, b = 0, ans = 0;

        while (a < M) cur_price += price[a++];

        while (b < N) {
            if (cur_price < K)
                ans++;

            cur_price -= price[b++];
            cur_price += price[a % N];
            a++;
        }

        if (N == M && ans > 0) ans = 1;

        cout << ans << '\n';
    }

    return 0;
}