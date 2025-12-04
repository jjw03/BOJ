#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * naive O(N) for lca
 */

int N;
vector<vector<int>> tree;
vector<int> depth, parent;

void init(){
    cin >> N;
    tree.resize(N);
    depth.resize(N, 0);
    parent.resize(N);

    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
}

void DFS(int cur = 0, int d = 1){
    depth[cur] = d;
    
    for(const int next : tree[cur]){
        if(depth[next] != 0) continue;
        DFS(next, d + 1);
        parent[next] = cur;
    }
}

int lca(int a, int b){
    //depth equalize
    int p = (depth[a] > depth[b] ? a : b);
    int c = (depth[a] > depth[b] ? b : a);
    while(depth[p] > depth[c]) p = parent[p];
    
    //find lca
    while(p != c){
        p = parent[p];
        c = parent[c];
    }

    return p + 1;
}

void solve(){
    DFS();  //calculate depth
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca(a - 1, b - 1) << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
