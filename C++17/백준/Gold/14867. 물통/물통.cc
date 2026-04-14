#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 연산 3가지에 대하여 각각 나올 수 있는 경우의 수는 2 + 2 + 2
*/

int a, b, c, d;


struct info {
    pair<int, int> container;
    int trial;

    info(pair<int, int> container, int trial) : container(container), trial(trial) {}
};

map<pair<int, int>, int> memo;

vector<pair<int, int>> calc_next(pair<int, int> cur) {
    vector<pair<int, int>> ret;
    
    // F(x)
    ret.push_back({ a, cur.second });
    ret.push_back({ cur.first, b });

    // E(x)
    ret.push_back({ 0, cur.second });
    ret.push_back({ cur.first, 0 });

    // M(x, y)
    int merged = cur.first + cur.second;
    ret.push_back({ max(0, merged - b), min(b, merged) });
    ret.push_back({ min(a, merged), max(0, merged - a) });

    return ret;
}

void bfs() {
    queue<info> to_visit;
    to_visit.push({ {0, 0}, 0 });

    memo.insert({ {0, 0}, 0 });

    while (!to_visit.empty()) {
        auto [cur, tt] = to_visit.front();
        to_visit.pop();

        vector<pair<int, int>> next = calc_next(cur);

        for (const pair<int, int>& nn : next) {
            if (memo.find(nn) != memo.end()) continue;

            memo.insert({ nn, tt + 1 });
            to_visit.push({ nn, tt + 1 });
        }
    }
}

void init() {
    cin >> a >> b >> c >> d;
}

void solve() {
    bfs();

    auto iter = memo.find({ c, d });
    if (iter == memo.end())
        cout << -1;
    else
        cout << (*iter).second;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}