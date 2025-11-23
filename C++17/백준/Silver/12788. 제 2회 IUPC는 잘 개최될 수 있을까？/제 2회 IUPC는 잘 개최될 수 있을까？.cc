#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 그리디
* 가장 많은 놈 뺏어서 주면 됨
* 부의 재분배
*/

int main() {
    FAST_IO;

    int N, M, K;
    cin >> N >> M >> K;

    priority_queue<int> pq;
    while (N--) {
        int in;
        cin >> in;

        pq.push(in);
    }

    int ans = 0, p = M * K;
    while (p > 0 && !pq.empty()) {
        p -= pq.top();
        pq.pop();
        ans++;
    }

    if (p > 0) {
        cout << "STRESS";
    }
    else {
        cout << ans;
    }

    return 0;
}