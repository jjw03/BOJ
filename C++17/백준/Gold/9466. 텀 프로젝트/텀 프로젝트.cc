#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 각 노드들의 출력 차수는 무조건 1이므로
* 두개 이상의 사이클이 서로 겹치는(맞닿는) 경우는 없다
* 
* 사이클이라 판단되면 return 1
* 사이클의 진입지점에서는 다시 return 0
*/

int tt, n;
vector<int> grouped, graph, stk, visited;

void init() {
    cin >> tt;
}

int DFS(int cur) {
    if (stk[cur]) return grouped[cur] = 1;
    if (visited[cur]) return 0;

    visited[cur] = 1;
    stk[cur] = 1;

    int ret = DFS(graph[cur]);
    if (ret) {
        // 사이클 시작점에서 반환값을 0으로 변경
        if (grouped[cur])
            ret = 0;
        grouped[cur] = 1;
    }

    stk[cur] = 0;

    return ret;
}

void solve() {
    while (tt--) {
        cin >> n;

        grouped.resize(n, 0);
        graph.resize(n);
        stk.resize(n, 0);
        visited.resize(n, 0);

        for (int& i : graph) {
            cin >> i;
            --i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                DFS(i);
        }

        for (const int& g : grouped) {
            if (!g) ++ans;
        }

        cout << ans << '\n';

        vector<int>().swap(grouped);
        vector<int>().swap(graph);
        vector<int>().swap(stk);
        vector<int>().swap(visited);
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}