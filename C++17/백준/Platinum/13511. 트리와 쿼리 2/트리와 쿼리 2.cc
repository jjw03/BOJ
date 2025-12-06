#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 경로의 비용: 루트까지의 경로 누적합을 이용
 *
 * k번째 정점
 * step(u->v) = x : u에서 v로 가는 단계수
 * 
 * case 1
 * step(u -> lca(u, v)) >= k : u로부터 k 만큼 이동
 *
 * case 2
 * step(u -> lca(u, v)) < k : v로부터 step(v -> lca(u, v)) - (k - step(u -> lca(u, v))) 만큼 이동
 */

const int bit_sz = 21;
int N;

vector<vector<pair<int, int>>> tree;
vector<vector<int>> sparse_table;
vector<int> depth;
vector<ll> dist;    //dist from root

struct step_count{
    int lca_node;
    int u_lca;
    int v_lca;
    step_count(int lca_node = 0, int u_lca = 0, int v_lca = 0)
        : lca_node(lca_node), u_lca(u_lca), v_lca(v_lca) {}
};

void DFS(int cur = 0, int d = 1){
    depth[cur] = d;

    for(const auto& [next, w] : tree[cur]){
        if(depth[next] != 0) continue;

        //move 1
        sparse_table[0][next] = cur;
        //prefix sum
        dist[next] = dist[cur] + w;
        
        DFS(next, d + 1);
    }
}

//move 2^p
void init_table(){
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
    sparse_table.resize(bit_sz, vector<int>(N));
    depth.resize(N);
    dist.resize(N);

    for(int i = 1; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        tree[u-1].push_back({v-1, w});
        tree[v-1].push_back({u-1, w});
    }   

    DFS();
    init_table();
}

int query(int node, int move){
    int ret = node;
    for(int b = bit_sz - 1; b >= 0; b--){
        if(move & (1 << b)){
            ret = sparse_table[b][ret];
        }
    }
    return ret;
}

// returns {lca node, step count}
step_count lca(int a, int b){
    if(a == b) return {a, 0, 0};

    int p = (depth[a] > depth[b] ? a : b);
    int q = (depth[a] > depth[b] ? b : a);

    //depth equalize
    int ret_step = depth[p] - depth[q];
    p = query(p, depth[p] - depth[q]);

    if(p == q) return {p, depth[a] > depth[b] ? ret_step : 0, depth[a] > depth[b] ? 0 : ret_step};

    int u_lca = ret_step, v_lca = 0;
    for(int b = bit_sz - 1; b >= 0; b--){
        int np = sparse_table[b][p], nq = sparse_table[b][q];
        if(np != nq){
            u_lca += (1 << b);
            v_lca += (1 << b);
            p = np, q = nq;
        }
    }

    //move 1
    return {sparse_table[0][p], (depth[a] > depth[b] ? u_lca : v_lca) + 1, (depth[a] > depth[b] ? v_lca : u_lca) + 1};
}   

//find kth node of a -> b
int find_kth(int a, int b, int k){
    if(a == b) return a;

    k--;

    //find lca and step(a -> lca(a, b))
    auto [l, al, bl] = lca(a, b);

    if(al >= k) return query(a, k);
    else{
        int move = bl - (k - al);
        return query(b, move);
    }
}

void solve(){
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            auto [l, ul, vl] = lca(u-1, v-1);
            ll a = dist[u-1] + dist[v-1] - 2 * dist[l];
            cout << a << '\n';
        }
        else{
            int u, v, k;
            cin >> u >> v >> k;
            cout << find_kth(u-1, v-1, k) + 1 << '\n';
        }
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
