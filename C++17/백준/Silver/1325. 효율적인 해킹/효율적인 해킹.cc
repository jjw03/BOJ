#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* BFS로 각 노드의 자식 개수를 모두 구한다
* 자식 노드에서 탐색을 시작하여 모든 부모 노드에 +1하는 과정을 반복하고
* 최대 값을 가지는 노드들을 출력한다
*/

int N, M;
vector<int> child, visited;
vector<vector<int>> graph;

void init() {
    cin >> N >> M;
    child.resize(N, 0);
    visited.resize(N, -1);
    graph.resize(N);

    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
}

int BFS(int s) {
    queue<int> to_visit;
    to_visit.push(s);
    visited[s] = s;

    int mark = s, maximum = 0;

    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();

        maximum = max(maximum, child[cur]);

        for (const int& next : graph[cur]) {
            if (visited[next] != mark) {
                visited[next] = mark;
                child[next]++;
                to_visit.push(next);
            }
        }
    }

    return maximum;
}

void solve() {
    int maximum = 0;
    for (int s = 0; s < N; s++) {
        maximum = max(maximum, BFS(s));
    }

    for (int node = 1; node <= N; node++) {
        if (child[node - 1] == maximum)
            cout << node << ' ';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}