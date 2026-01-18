#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 가능한 edge 검토 O(N^2)
 */

int N, K, from, to;
vector<string> code;
vector<vector<int>> graph;

vector<int> bfs(){
    vector<int> prv(N);
    prv[from - 1] = from - 1;

    vector<int> visited(N);
    visited[from - 1] = 1;

    queue<int> to_visit;
    to_visit.push(from - 1);

    while(!to_visit.empty()){
        int cur = to_visit.front();
        to_visit.pop();

        for(const int& next : graph[cur]){
            if(visited[next]) continue;
            to_visit.push(next);
            visited[next] = 1;
            prv[next] = cur;
        }
    }

    if(!visited[to - 1]) return vector<int>();

    vector<int> path;
    for(int s = to - 1; s != from - 1; s = prv[s])
        path.push_back(s + 1);
    path.push_back(from);

    return path;
}

void init(){
    cin >> N >> K;
    code.resize(N);
    graph.resize(N);

    for(string& s : code) cin >> s;

    cin >> from >> to;

    // make graph
    for(int i = 0; i < N; ++i){
        for(int k = 0; k < N; ++k){
            if(i == k) continue;

            int cnt = 0;
            for(int j = 0; j < K; ++j)
                cnt += (code[i][j] != code[k][j]);
            
            if(cnt == 1){
                graph[i].push_back(k);
                graph[k].push_back(i);
            }
        }
    }
}

void solve(){
    vector<int> ans = bfs();
    if(ans.empty())
        cout << -1;
    else{
        for(auto riter = ans.rbegin(); riter != ans.rend(); riter++)
            cout << *riter << ' ';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
