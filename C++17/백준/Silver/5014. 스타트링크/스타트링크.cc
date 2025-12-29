#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

//BFS

int F, S, G, U, D;
vector<int> dist;

void init() {
    cin >> F >> S >> G >> U >> D;
    dist.resize(F + 1, INT_MAX);
    dist[S] = 0;
}

void BFS() {
    queue<int> to_visit;
    to_visit.push(S);

    while (!to_visit.empty()) {
        int cur = to_visit.front();
        to_visit.pop();

        int up = cur + U, down = cur - D;
        if (up <= F && dist[cur] + 1 < dist[up]) {
            dist[up] = dist[cur] + 1;
            to_visit.push(up);
        }

        if (1 <= down && dist[cur] + 1 < dist[down]) {
            dist[down] = dist[cur] + 1;
            to_visit.push(down);
        }
    }
}

void solve() {
    BFS();

    if (dist[G] != INT_MAX)
        cout << dist[G];
    else
        cout << "use the stairs";
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}