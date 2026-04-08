#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;

void init() {
    cin >> N;
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    while (N--) {
        int n, t = 0;
        cin >> n;
        while (n--) {
            int in; 
            cin >> in;
            t += in;
        }
        pq.push(t);
    }

    ll ans = 0, t = 0;
    while (!pq.empty()) {
        ans += t + pq.top();
        t += pq.top();
        pq.pop();
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
