#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 임의의 두 도시 사이를 잇는 경로는 유일하므로
 * 도시 그래프는 트리 구조를 가진다
 *
 * 두 도시를 연결하는 경로는 두 도시의 LCA까지의 경로를 합친것과 같고
 * 두 도시의 LCA를 구하는 방법은 희소 배열을 사용한다
 *
 * 이제 위에서 구한 경로상의 도로의 길이들 중 최댓값/최솟값을 구해야한다
 * 각 경로들을 모두 완전탐색하면서 값을 구하면 TLE가 발생하므로
 * 각 노드에서 2^p만큼 이동했을때의 경로 최댓값/최솟값을 저장하는 희소배열을 만든다
 *
 * 트리의 루트 노드는 1번으로 정한다
 */

const int bit_sz = 21;
int N;

vector<vector<int>> table_node;
vector<vector<pair<int, int>>> table_minMax, tree;
vector<int> depth;

inline pair<int, int> clamp(const pair<int, int>& a, const pair<int, int>& b){
    return {min(a.first, b.first), max(a.second, b.second)};
}

void DFS(int cur = 0, int d = 1){
    depth[cur] = d;

    for(const auto& [next, w] : tree[cur]){
        if(depth[next] != 0) continue;
        
        //move 1
        table_node[0][next] = cur;
        table_minMax[0][next] = {w, w};

        DFS(next, d + 1);
    }
}

//move 2^p
void init_table(){
    for(int p = 1; p < bit_sz; p++){
        for(int node = 0; node < N; node++){
            int prv = table_node[p-1][node];
            table_node[p][node] = table_node[p-1][prv];
            table_minMax[p][node] = clamp(table_minMax[p-1][node], table_minMax[p-1][prv]);
        }
    }
}

void init(){
    cin >> N;
    tree.resize(N);
    table_node.resize(bit_sz, vector<int>(N));
    table_minMax.resize(bit_sz, vector<pair<int, int>>(N));
    depth.resize(N);

    for(int i = 1; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tree[a-1].push_back({b-1, c});
        tree[b-1].push_back({a-1, c});
    }

    DFS();
    init_table();
}

int query(int node, int move, pair<int, int>& path){
    int ret = node;
    for(int b = bit_sz - 1; b >= 0; b--){
        if(move & (1 << b)){
            path = clamp(path, table_minMax[b][ret]);
            ret = table_node[b][ret];
        }
    }
    return ret;
}

pair<int, int> lca(int a, int b){
    if(a == b) return {0, 0};

    pair<int, int> path = {INT_MAX, 0};
    int p = (depth[a] > depth[b] ? a : b);
    int q = (depth[a] > depth[b] ? b : a);

    //depth equalize
    p = query(p, depth[p] - depth[q], path);

    if(p == q) return path;
    
    pair<int, int> path2 = {INT_MAX, 0};
    for(int b = bit_sz - 1; b >= 0; b--){
        int np = table_node[b][p], nq = table_node[b][q];
        if(np != nq){
            path = clamp(path, table_minMax[b][p]);
            path2 = clamp(path2, table_minMax[b][q]);

            p = np;
            q = nq;
        }
    }
    
    path = clamp(path, table_minMax[0][p]);
    path2 = clamp(path2, table_minMax[0][q]);

    return clamp(path, path2);
}

void solve(){
    int q;
    cin >> q;

    while(q--){
        int d, e;
        cin >> d >> e;
        auto [s, l] = lca(d-1, e-1);
        cout << s << ' ' << l << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
