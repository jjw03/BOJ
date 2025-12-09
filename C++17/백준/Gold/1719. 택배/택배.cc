#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* O(N^3)
* 플로이드 워셜
* 경로 갱신 부분만 좀 다름
* a->b에서 거쳐가는 노드를 저장한 배열을 arr[a][b]이라 할 때
* a->b를 갱신하는 경로 a->k->b의 거쳐가는 노드는
* arr[a][b] = arr[a][k]임
*/

int n, m;
vector<vector<int>> graph, ans;

void init() {
    cin >> n >> m;

    graph.resize(n, vector<int>(n, INT_MAX));
    ans.resize(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--)
        graph[i][i] = 0;

    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        
        if (graph[a - 1][b - 1] > t) {

            graph[a - 1][b - 1] = min(graph[a - 1][b - 1], t);
            graph[b - 1][a - 1] = graph[a - 1][b - 1];
            
            // 바로 다음 노드들로 초기화
            ans[a - 1][b - 1] = b;
            ans[b - 1][a - 1] = a;
        }
    }
}

void solve() {
    for (int k = 0; k < n; k++) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (graph[a][k] == INT_MAX || graph[k][b] == INT_MAX) continue;
                if (graph[a][b] > graph[a][k] + graph[k][b]) {
                    ans[a][b] = ans[a][k];  //경로를 갱신할 때는 a->k로 가는 경로의 이동 지점을 저장한다
                    graph[a][b] = graph[a][k] + graph[k][b];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (i == k) {
                cout << '-' << ' ';
                continue;
            }
            cout << ans[i][k] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    FAST_IO;
   
    init();
    solve();

    return 0;
}