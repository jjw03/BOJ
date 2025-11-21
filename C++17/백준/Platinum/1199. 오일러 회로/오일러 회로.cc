#include <bits/stdc++.h>
using namespace std;

int N;
vector<unordered_map<int, int>> graph;

void euler_DFS(int cur) {
    while (!graph[cur].empty()) {
        int next = graph[cur].begin()->first;
        graph[cur][next]--;
        graph[next][cur]--;

        if (graph[cur][next] == 0) {
            graph[cur].erase(next);
            graph[next].erase(cur);
        }

        euler_DFS(next);
    }

    cout << cur + 1 << ' ';
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    graph.resize(N);

    bool is_circuit = true;
    for (int r = 0; r < N; r++) {
        int degree = 0;
        for (int c = 0; c < N; c++) {
            int in; 
            cin >> in;

            degree += in;

            if (r == c || in == 0) continue;

            graph[r].insert({ c, in });
        }
        is_circuit &= (degree % 2 == 0);
    }

    if (!is_circuit) {
        cout << -1;
        return 0;
    }

    euler_DFS(0);

    return 0;
}