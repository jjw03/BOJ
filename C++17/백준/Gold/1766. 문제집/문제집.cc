#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 위상정렬을 적용하되, 쉬운 문제들부터 탐색한다
* DFS 방식은 너무 복잡해지고, BFS가 간단한듯
*/

int N, M;
vector<vector<int>> graph;
vector<int> visited, indegree;

// 우선순위 큐를 사용
// 이미 진입한 branch에 대해서는 순서가 유지되므로 우선순위큐 사용가능
void bfs(vector<int>& order) {
    priority_queue<int, vector<int>, greater<int>> to_visit;
    for (int s = 0; s < N; ++s) {
        if (indegree[s] == 0) {
            to_visit.push(s);
            visited[s] = 1;
        }
    }

    while (!to_visit.empty()) {
        int cur = to_visit.top();
        to_visit.pop();

        if(indegree[cur] == 0)
            order.push_back(cur + 1);

        for (const int& next : graph[cur]) {
            if (visited[next]) continue;
            if (--indegree[next] == 0) {
                to_visit.push(next);
                visited[next] = 1;
            }
        }
    }
}

void init() {
    cin >> N >> M;

    graph.resize(N);
    indegree.resize(N, 0);
    visited.resize(N, 0);

    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        ++indegree[b - 1];
    }
}

void solve() {
    vector<int> order;
    bfs(order);

    for (int i : order) cout << i << ' ';
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
