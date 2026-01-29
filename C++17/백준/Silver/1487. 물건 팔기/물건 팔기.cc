#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;

struct st {
    int price;
    int cost;

    st(int price = 0, int cost = 0)
        : price(price), cost(cost) { }

    bool operator<(const st& other) const {
        return (price != other.price ? other.price < price : other.cost < cost);
    }
};

vector<st> vec;

void init() {
    cin >> N;

    vec.resize(N);

    for (st& s : vec)
        cin >> s.price >> s.cost;

    sort(vec.begin(), vec.end());
}

void solve() {
    vector<int> profit(1e6 + 1, 0);
    for (int p = 1e6; p > 0; --p) {
        int t = 0;
        for (int i = 0; i < N; ++i) {
            if (vec[i].price < p) break;
            if (p - vec[i].cost > 0)
                t += p - vec[i].cost;
        }
        profit[p] = t;
    }

    int ans = 0, tp = 0;
    for (int p = 1e6; p >= 0; --p) {
        if (tp <= profit[p]) {
            tp = profit[p];
            ans = p;
        }
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
