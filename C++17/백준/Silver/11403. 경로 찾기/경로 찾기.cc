#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 플로이드 워셜
*/

int N;
int graph[100][100];

void init() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k)
            cin >> graph[i][k];
    }
}

void solve() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                graph[i][j] |= graph[i][k] & graph[k][j];   // i -> j if i -> k and k -> j
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k)
            cout << graph[i][k] << ' ';
        cout << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
