#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int cnt = 0, ans = 1;
    vector<int> sieve(N + 1, 1);

    for (int i = 2; i <= N; i++) {
        if (sieve[i] == 0) continue;
        for (int k = 1; k * i <= N; k++) {
            if (sieve[i * k] == 0) continue;
            sieve[k * i] = 0;
            cnt++;
            if (cnt == K) ans = k * i;
        }
    }

    cout << ans;

    return 0;
}
