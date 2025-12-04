#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* f_n(x)는 그래프 상에서 노드 x를 기점으로 n번 이동한 결과를 계산한다
*/

const int bit_sz = 21;
int m;

vector<vector<int>> sparse_table;

void init() {
    cin >> m;
    sparse_table.resize(bit_sz, vector<int>(m));

    // move 1
    for (int i = 0; i < m; i++) {
        cin >> sparse_table[0][i];
        sparse_table[0][i]--;
    }

    // move 2^p
    for (int p = 1; p < bit_sz; p++) {
        for (int node = 0; node < m; node++) {
            int prv = sparse_table[p - 1][node];
            sparse_table[p][node] = sparse_table[p - 1][prv];
        }
    }
}

int query(int node, int move) {
    int ret = node;
    for (int b = bit_sz - 1; b >= 0; b--) {
        if (move & (1 << b))
            ret = sparse_table[b][ret];
    }
    return ret;
}

int main() {
    FAST_IO;

    init();

    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;
        cout << query(x - 1, n) + 1 << '\n';
    }

    return 0;
}
