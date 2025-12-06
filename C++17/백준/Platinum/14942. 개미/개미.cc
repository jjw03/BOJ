#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * lca를 구하듯이 각 개미에 대하여 이동 가능한 거리만 추가하면 된다
 * 축적 에너지 값이 양수라면 계속 이동
 * 음수라면 이동하지 않음
 *
 * 1번방을 루트로 삼아서 별도의 lca는 구하지 않음
 */

const int bit_sz = 21;
int N;

vector<vector<pair<int, int>>> tree;
vector<vector<int>> sparse_table;
vector<int> depth;
vector<ll> dist, energy;

void DFS(int cur = 0, int d = 1){
    depth[cur] = d;

    for(const auto& [next, w] : tree[cur]){
        if(depth[next] != 0) continue;

        sparse_table[0][next] = cur;    //move 1
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
    energy.resize(N);
    
    for(ll& i : energy) cin >> i;

    for(int i = 1; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;

        tree[a-1].push_back({b-1, c});
        tree[b-1].push_back({a-1, c});
    }

    DFS();
    init_table();
}

//val을 가지고 가장 멀리 갈 수 있는 노드를 반환
int query(int start, ll val){
    int ret = start;
    for(int b = bit_sz - 1; b >= 0; b--){
        int next = sparse_table[b][ret];
        ll d = dist[ret] - dist[next];
        if(val >= d){
            val -= d;
            ret = next;
        }
    }
    return ret + 1;
}

void solve(){
    for(int start = 0; start < N; start++){
        cout << query(start, energy[start]) << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
