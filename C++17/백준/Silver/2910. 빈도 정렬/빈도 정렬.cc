#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, C;
map<int, int> cnt, seq;

struct st {
    int num;
    int cnt;
    int seq;
    st(int num, int cnt, int seq)
        : num(num), cnt(cnt), seq(seq) { }
    bool operator<(const st& other) const {
        return (cnt != other.cnt ? cnt < other.cnt : other.seq < seq);
    }
};

priority_queue<st> pq;

void init() {
    cin >> N >> C;

    for(int i = 0; i < N; ++i) {
        int in; cin >> in;
        auto iter = cnt.find(in);
        if (iter == cnt.end()) {
            cnt.insert({ in, 1 });
            seq.insert({ in, i });
        }
        else
            ++cnt[in];
    }
}

void solve() {
    for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
        auto [num, cnt] = *iter;
        pq.push(st(num, cnt, seq[num]));
    }

    while (!pq.empty()) {
        for (int i = 0; i < pq.top().cnt; ++i)
            cout << pq.top().num << ' ';
        pq.pop();
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
