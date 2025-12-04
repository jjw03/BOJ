#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * lca using sparse table, O(lg N)
 * 초기 depth를 구할 때 루트로부터 각 노드까지의 거리를 누적하고
 * lca를 구하는 과정에서 노드 간의 누적 거리 차이를 합해주면 답을 구할 수 있음
 */

const int bit_sz = 17;
int N;
vector<vector<pair<int, int>>> tree;
vector<vector<int>> sparse_table;
vector<int> depth; 
vector<ll> root_dist;   //root_dist를 통해 루트까지의 거리를 저장(누적합)

void DFS(int cur = 0, int d = 1){
    depth[cur] = d;

    for(const auto& [next, w] : tree[cur]){
        if(depth[next] != 0) continue;
        sparse_table[0][next] = cur;    // move 1
        root_dist[next] = root_dist[cur] + w;   // prefix_sum
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
    root_dist.resize(N, 0);
    sparse_table.resize(bit_sz, vector<int>(N));

    for(int i = 1; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tree[a-1].push_back({b-1, c});
        tree[b-1].push_back({a-1, c});
    }

    DFS();  //calculate depth
    init_table();   //init sparse table
}

int query(int node, int move, ll& dist){
    int ret = node;
    for(int b = bit_sz - 1; b >= 0; b--){
        if(move & (1 << b)){
            int next= sparse_table[b][ret];
            dist += root_dist[ret] - root_dist[next];
            ret = next;
        }
    }
    return ret;
}

ll lca(int a, int b){
    ll dist = 0;
    int p = (depth[a] > depth[b] ? a : b);
    int q = (depth[a] > depth[b] ? b : a);
        
    //depth equalize
    p = query(p, depth[p] - depth[q], dist);

    if(p == q) return dist;

    //find lca
    for(int b = bit_sz - 1; b >= 0; b--){
        if(sparse_table[b][p] != sparse_table[b][q]){
            int np = sparse_table[b][p], nq = sparse_table[b][q];
            dist += root_dist[p] - root_dist[np];
            dist += root_dist[q] - root_dist[nq];
            p = np;
            q = nq;
        }
    }

    int np = sparse_table[0][p], nq = sparse_table[0][q];
    dist += root_dist[p] - root_dist[np] + root_dist[q] - root_dist[nq];

    return dist;
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
