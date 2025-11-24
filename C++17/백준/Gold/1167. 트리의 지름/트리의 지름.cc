#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int V;
vector<vector<pair<int, int>>> graph;

void init(){
    cin >> V;
    graph.resize(V);
    for(int i = 0; i < V; i++){
        int node;
        cin >> node;

        int a, w;
        while(cin >> a){
            if(a == -1) break;
            cin >> w;
            graph[node - 1].push_back({a-1, w});
        }    
    }
}

pair<int, int> find_farthest(int start){
    pair<int, int> ret = {0, 0};
    
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    queue<pair<int, int>> to_visit;
    to_visit.push({start, 0});

    while(!to_visit.empty()){
        const auto [cur, curd] = to_visit.front();
        to_visit.pop();

        if(ret.second < curd) ret = {cur, curd};

        for(const auto& [next, w] : graph[cur]){
            if(dist[next] != INT_MAX) continue;

            int new_d = w + curd;
            if(new_d < dist[next]){
                dist[next] = new_d;
                to_visit.push({next, new_d});
            }
        }
    }

    return ret;
}

int main(){
    FAST_IO;

    init();

    auto [s, t] = find_farthest(0);
    cout << find_farthest(s).second;

    return 0;
}
