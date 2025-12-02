#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * BFS로 각 노드까지의 최대 운반 가능 무게 갱신
 */

int N, M, s, e;
vector<map<int, int>> graph;

void init(){
    cin >> N >> M;

    graph.resize(N);

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;

        auto iter = graph[a - 1].find(b - 1);
        if(iter == graph[a - 1].end()){
            graph[a - 1].insert({b - 1, c});
            graph[b - 1].insert({a - 1, c});
        }
        else{
            (*iter).second = max((*iter).second, c);
            graph[b - 1][a - 1] = max(graph[b - 1][a - 1], c);
        }
    }

    cin >> s >> e;
}

int BFS(){
    vector<int> dist(N, 0);

    queue<pair<int, int>> to_visit;
    to_visit.push({s - 1, INT_MAX});

    while(!to_visit.empty()){
        auto [cur, w] = to_visit.front();
        to_visit.pop();

        if(dist[cur] > w) continue;
        
        for(auto iter = graph[cur].begin();
                iter != graph[cur].end(); iter++){
            const auto& [next, d] = *iter;

            int nw = min(d, w);
            if(nw > dist[next]){
                dist[next] = nw;
                to_visit.push({next, nw});
            }
        }
    }

    return dist[e - 1];
}

int main(){
    FAST_IO;

    init();
    cout << BFS();

    return 0;
}