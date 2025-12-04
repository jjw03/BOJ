#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int bit_sz = 32;

void make_table(vector<vector<int>>& table, int n) {
    table.resize(bit_sz, vector<int>(n));

    for (int i = 0; i < n; i++) {
        cin >> table[0][i];
        table[0][i]--;
    }

    for (int p = 1; p < bit_sz; p++) {
        for (int node = 0; node < n; node++) {
            int prv = table[p - 1][node];
            table[p][node] = table[p - 1][prv];
        }
    }
}

int query(const vector<vector<int>>& table, int node, int move) {
    int ret = node;
    for (int b = bit_sz - 1; b >= 0; b--) {
        if (move & (1 << b))
            ret = table[b][ret];
    }
    return ret;
}

int main() {
    FAST_IO;

    int n, m;
    while (cin >> n >> m) {
        if (n == 0) break;

        vector<vector<int>> table;
        make_table(table, n);

        string s;

        cin.ignore();
        getline(cin, s);

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[query(table, i, m)] = i;

        for (const int& i : ans)
            cout << s[i];
        cout << '\n';
    }

    return 0;
}
