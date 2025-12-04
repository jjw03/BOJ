#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * lca using sparse table, O(lg N)
 */

const int bit_sz = 17;
int N;
vector<vector<int>> tree, sparse_table;
vector<int> depth;

void DFS(int cur = 0, int d = 1){
    depth[cur] = d;

    for(const int& next : tree[cur]){
        if(depth[next] != 0) continue;
        sparse_table[0][next] = cur;    // move 1
        DFS(next, d + 1);
    }
}

void init_table(){
    //move 2^p
    for(int p = 1; p < bit_sz; p++){
        for(int node = 0; node < N; node++){
            int prv = sparse_table[p-1][node];
            sparse_table[p][node] = sparse_table[p-1][prv];
        }
    }
}

void init(){
    cin >> N;
    tree.resize(N);
    depth.resize(N, 0);
    sparse_table.resize(bit_sz, vector<int>(N));

    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    DFS();  //calculate depth
    init_table();   //init sparse table
}

int query(int node, int move){
    int ret = node;
    for(int b = bit_sz - 1; b >= 0; b--){
        if(move & (1 << b))
            ret = sparse_table[b][ret];
    }
    return ret;
}

int lca(int a, int b){
    int p = (depth[a] > depth[b] ? a : b);
    int q = (depth[a] > depth[b] ? b : a);
        
    //depth equalize
    p = query(p, depth[p] - depth[q]);
    
    if(p == q) return p + 1;

    //find lca
    //가장 큰 이동거리부터 찾음
    //만약 이동 결과가 같다면 해당 비트를 버리고
    //이동 결과가 다르다면 해당 비트를 취함
    for(int b = bit_sz - 1; b >= 0; b--){
        if(sparse_table[b][p] != sparse_table[b][q]){
            p = sparse_table[b][p];
            q = sparse_table[b][q];
        }
    }

    return sparse_table[0][p] + 1;
}

void solve(){
    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca(a-1, b-1) << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
