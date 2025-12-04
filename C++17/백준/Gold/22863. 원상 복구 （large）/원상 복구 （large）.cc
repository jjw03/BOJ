#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 희소배열
* 결과 배열을 수열 D에 따라 다시 K번 배치하면 됨
*/

const int bit_sz = 64;
int N;
ll K;

int original[1'000'000];
int sparse_table[64][1'000'000];

void init() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> original[i];
    }

    // move 1
    for (int i = 0; i < N; i++) {
        cin >> sparse_table[0][i];
        sparse_table[0][i]--;
    }

    //move 2^p
    for (int p = 1; p < bit_sz; p++) {
        for (int node = 0; node < N; node++) {
            int prv = sparse_table[p - 1][node];
            sparse_table[p][node] = sparse_table[p - 1][prv];
        }
    }
}

int query(int node, ll move) {
    int ret = node;
    for (int b = bit_sz - 1; b >= 0; b--) {
        if (move & (1ll << b))
            ret = sparse_table[b][ret];
    }
    return ret;
}

int main() {
    FAST_IO;

    init();

    vector<int> ans(N);

    for (int i = 0; i < N; i++)
        ans[query(i, K)] = original[i];

    for (const int& i : ans)
        cout << i << ' ';

    return 0;
}
