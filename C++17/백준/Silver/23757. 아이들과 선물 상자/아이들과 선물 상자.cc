#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M;
priority_queue<int> pq;

void init() {
    cin >> N >> M;

    while (N--) {
        int in; cin >> in;
        pq.push(in);
    }
}

void solve() {
    bool is_ok = true;
    while (M--) {
        int w;
        cin >> w;

        int cur = pq.top();
        pq.pop();

        if (cur < w) {
            is_ok = false;
            break;
        }
        else {
            cur -= w;
            if (cur > 0)
                pq.push(cur);
        }
    }

    cout << (is_ok ? 1 : 0);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
