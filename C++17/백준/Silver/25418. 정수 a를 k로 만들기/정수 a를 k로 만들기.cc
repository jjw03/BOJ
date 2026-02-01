#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int sz = 1'000'000;
int A, K;
int graph[sz + 1];

void bfs() {
    queue<int> to_visit;
    to_visit.push(A);
    graph[A] = 0;

    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();

        int add = cur + 1, mul = cur << 1;
        if (add <= sz && graph[add] > graph[cur] + 1) {
            graph[add] = graph[cur] + 1;
            to_visit.push(add);
        }

        if (mul <= sz && graph[mul] > graph[cur] + 1) {
            graph[mul] = graph[cur] + 1;
            to_visit.push(mul);
        }
    }
}

void init() {
    cin >> A >> K;

    fill(graph, graph + sz + 1, INT_MAX);
}

void solve() {
    bfs();
    cout << graph[K];
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
