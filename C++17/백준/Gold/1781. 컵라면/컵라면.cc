#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct ramen {
    int val;
    int deadline;
    ramen(int val = 0, int deadline = 0)
        : val(val), deadline(deadline) { }
};

namespace cmp {
    struct deadline {
        bool operator()(const ramen& a, const ramen& b) const {
            if (a.deadline != b.deadline) return a.deadline > b.deadline;
            return a.val > b.val;
        }
    };

    struct val {
        bool operator()(const ramen& a, const ramen& b) const {
            if (a.val != b.val) return a.val > b.val;
            return a.deadline > b.deadline;
        }
    };
}

int main() {
    FAST_IO;

    int N;
    cin >> N;

    priority_queue<ramen, vector<ramen>, cmp::deadline> pq1;
    while (N--) {
        int d, v;
        cin >> d >> v;
        pq1.push({ v, d });
    }

    priority_queue<ramen, vector<ramen>, cmp::val> pq2;
    int date = 0;
    while (!pq1.empty()) {
        if (date < pq1.top().deadline) {
            date++;
            pq2.push(pq1.top());
        }
        else if (pq1.top().val > pq2.top().val) {
            pq2.pop();
            pq2.push(pq1.top());
        }
        pq1.pop();
    }

    int ans = 0;
    while (!pq2.empty()) {
        ans += pq2.top().val;
        pq2.pop();
    }
    cout << ans;

    return 0;
}
