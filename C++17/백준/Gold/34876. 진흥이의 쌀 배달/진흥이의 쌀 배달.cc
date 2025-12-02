#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 어떤 임의의 노드에서 서브트리들의 쌀포대를 모두 옮기는 과정은
 * 별다른 최적화 방법이 존재하지 않는다(항상 최솟값이다)
 * 따라서 dfs로 서브트리의 모든 쌀포대를 옮기면서 시간을 누적한다
 */

int N, K;
vector<int> rice, visited;
vector<vector<pair<int, int>>> graph;

void init(){
    cin >> N >> K;
    visited.resize(N + 1, 0);
    rice.resize(N + 1);
    graph.resize(N + 1);

    for(int i = 1; i <= N; i++)
        cin >> rice[i];

    for(int i = N; i > 0; i--){
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
}

ll DFS(int cur){
    visited[cur] = 1;

    ll ret = 0;
    // 모든 서브트리들의 비용 계산
    for(const auto& [next, w] : graph[cur]){
        if(visited[next]) continue;

        ret += DFS(next);
        
        // 다음 노드 -> 현재 노드 비용 계산(왕복)
        ret += 2 * w * (rice[next] / K + (rice[next] % K > 0 ? 1 : 0));
        rice[cur] += rice[next]; // 쌀 합치기
    }
    
    return ret;
}

int main(){
    FAST_IO;
    
    init();
    cout << DFS(0);

    return 0;
}
