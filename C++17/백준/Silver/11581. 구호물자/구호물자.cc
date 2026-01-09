#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// 사이클 존재여부 판별

int N;
vector<vector<int>> graph;

bool DFS(vector<int>& visited, vector<int>& stk, int cur) {
    if (cur == N - 1)
        return false;
    if (stk[cur])
        return true;
    if (visited[cur])
        return false;

    stk[cur] = 1;
    visited[cur] = 1;

    bool ret = false;
    for (const int& next : graph[cur])
        ret |= DFS(visited, stk, next);

    stk[cur] = 0;

    return ret;
}

void init() {
    cin >> N;
    graph.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        int M; cin >> M;
        while (M--) {
            int node; cin >> node;
            graph[i].push_back(node - 1);
        }
    }
}

void solve() {
    vector<int> visited(N - 1, 0), stk(N - 1, 0);
    cout << (DFS(visited, stk, 0) ? ("CYCLE") : ("NO CYCLE"));
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}