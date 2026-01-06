#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int bit_sz = 14;
int tt, N;
int sparse_table[bit_sz][10'000], level[10'000], has_parent[10'000];
vector<vector<int>> edge;

void init() {
    cin >> tt;
}

void dfs(int cur, int depth = 1) {
    level[cur] = depth;
    
    for (const int& next : edge[cur]) {
        dfs(next, depth + 1);
    }
}

void init_table() {
    for (int p = 1; p < bit_sz; ++p) {
        for (int node = 0; node < N; ++node) {
            int prv = sparse_table[p - 1][node];
            sparse_table[p][node] = sparse_table[p - 1][prv];
        }
    }
}

int move(int node, int move_cnt) {
    int ret = node;
    for (int b = bit_sz - 1; b >= 0; --b) {
        if (move_cnt & (1 << b)) {
            ret = sparse_table[b][ret];
        }
    }
    return ret;
}

int query(int a, int b) {
    int p = (level[a] > level[b] ? a : b);
    int q = (level[a] > level[b] ? b : a);

    p = move(p, level[p] - level[q]);

    if (p == q) return p + 1;

    for (int b = bit_sz - 1; b >= 0; --b) {
        int np = sparse_table[b][p], nq = sparse_table[b][q];
        if (np != nq) {
            p = np, q = nq;
        }
    }

    return sparse_table[0][p] + 1;
}

void solve() {
    while (tt--) {
        cin >> N;

        memset(sparse_table, 0, sizeof(sparse_table));
        memset(level, 0, sizeof(level));
        memset(has_parent, 0, sizeof(has_parent));
        edge.resize(N);

        // init table
        for(int i = N - 1; i > 0; --i) {
            int a, b;
            cin >> a >> b;
            sparse_table[0][b - 1] = a - 1;
            has_parent[b - 1] = 1;
            edge[a - 1].push_back(b - 1);
        }

        init_table();

        int parent = 0;
        while (has_parent[parent])
            ++parent;
        dfs(parent);

        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b - 1) << '\n';

        vector<vector<int>>().swap(edge);
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}