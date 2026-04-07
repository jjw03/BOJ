#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 그리디
*/

struct cmp_ascend {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

struct cmp_descend {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    }
};

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_ascend> pq_org;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_descend> pq_room;

void init() {
    cin >> N;

    while (N--) {
        int s, e;
        cin >> s >> e;

        pq_org.push({ s, e });
    }
}

void solve() {
    int ans = 0;
    while (!pq_org.empty()) {
        auto [s, e] = pq_org.top();

        while (!pq_room.empty() && pq_room.top().second <= s)
            pq_room.pop();

        pq_room.push({ s, e });
        pq_org.pop();

        ans = max(ans, (int)pq_room.size());
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
