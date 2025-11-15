#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    struct _pair {
        int num;
        int idx;
        _pair(int num = 0, int idx = 0) : num(num), idx(idx) {}
        bool operator<(const _pair& other) const {
            if (other.num != num) return other.num < num;
            return other.idx < idx;
        }
    };

    vector<int> vec(N);
    priority_queue<_pair> pq;
    for (int idx = 0; idx < N; idx++) {
        cin >> vec[idx];
        pq.push(_pair(vec[idx], idx + 1));
    }

    int M;
    cin >> M;
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            vec[i - 1] = v;
            pq.push(_pair(v, i));
        }
        else {
            while (vec[pq.top().idx - 1] != pq.top().num)
                pq.pop();
            cout << pq.top().idx << '\n';
        }
    }

    return 0;
}