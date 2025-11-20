#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> degree;
vector<map<int, int>> graph;

bool is_circuit() {
    bool ret = true;
    for (const int i : degree) ret &= (i % 2 == 0);
    return ret;
}

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

    degree.resize(N);
    graph.resize(N);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int in; 
            cin >> in;

            degree[r] += in;

            if (r == c || in == 0) continue;

            graph[r].insert({ c, in });
        }
    }

    if (!is_circuit()) {
        cout << -1;
        return 0;
    }

    euler_DFS(0);

    return 0;
}