#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, M, R, nth = 1;
vector<int> visited;
vector<set<int>> graph;

void init(){
    cin >> N >> M >> R;
    graph.resize(N);
    visited.resize(N, 0);

    while(M--){
        int u, v;
        cin >> u >> v;
        graph[u - 1].insert(v - 1);
        graph[v - 1].insert(u - 1);
    }
}

void DFS(int cur){
    visited[cur] = nth++;
    for(auto iter = graph[cur].begin(); iter != graph[cur].end(); iter++){
        if(visited[*iter] == 0) DFS(*iter);
    }
}

void solve(){
    DFS(R - 1);
    
    for(const int& i : visited)
        cout << i << '\n';
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
