#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 1 -> min(v_1, v_2) + v_1 -> v_2 + max(v_1, v_2) -> N
 */

int N, E, v_1, v_2;
vector<vector<pair<int, int>>> graph;

void init(){
    cin >> N >> E;
    graph.resize(N);
    while(E--){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
    cin >> v_1 >> v_2;
    v_1--, v_2--;
}

struct cmp{
    bool operator()(const pair<int, ll>& a, const pair<int, ll>& b) const{
        if(a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    }
};

pair<ll, ll> dijkstra(int s, int e1, int e2 = -1){
    vector<ll> dist(N, LLONG_MAX);
    dist[s] = 0;

    priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> to_visit;
    to_visit.push({s, 0});

    while(!to_visit.empty()){
        auto [cur, d] = to_visit.top();
        to_visit.pop();

        if(dist[cur] < d) continue;

        for(const auto& [next, w] : graph[cur]){
            ll nd = d + w;
            if(nd < dist[next]){
                dist[next] = nd;
                to_visit.push({next, nd});
            }
        }
    }

    pair<ll, ll> ret = {dist[e1], (e2 != -1 ? dist[e2] : -1)};

    return ret;
}

int main(){
    FAST_IO;

    init();
    
    pair<ll, ll> s_v = dijkstra(0, v_1, v_2);
    ll v_v = dijkstra(v_1, v_2).first;
    pair<ll, ll> v_e = {dijkstra(v_1, N - 1).first, dijkstra(v_2, N - 1).first};

    if(v_v == LLONG_MAX){
        cout << -1;
        return 0;
    }

    // combination 1: s->v_1->v_2->e
    ll ans_1 = s_v.first + v_v + v_e.second;
    if(s_v.first == LLONG_MAX || v_e.second == LLONG_MAX)
        ans_1 = LLONG_MAX;
    
    // combination 2: s->v_2->v_1->e
    ll ans_2 = s_v.second + v_v + v_e.first;
    if(s_v.second == LLONG_MAX || v_e.second == LLONG_MAX)
        ans_2 = LLONG_MAX;

    ll ans = min(ans_1, ans_2);
    cout << (ans == LLONG_MAX ? -1 : ans);

    return 0;
}
