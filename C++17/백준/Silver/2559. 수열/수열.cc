#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, K;
int arr[100'000];

void init() {
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];
}

void solve() {
    int ans = 0;
    for (int i = 0; i < K; ++i)
        ans += arr[i];

    int prv = ans;
    for (int i = K; i < N; ++i) {
        int temp = prv - arr[i - K] + arr[i];
        ans = max(ans, temp);
        prv = temp;
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
