#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N, vector<int>(N, 0));
    while (M--) {
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = 1;
        g[b - 1][a - 1] = 1;
    }

    vector<int> cnt(N);

    for (int s = 0; s < N; s++) {
        vector<int> dist(N, 100);
        dist[s] = 0;

        queue<int> to_visit;
        to_visit.push(s);
        
        while (!to_visit.empty()) {
            int cur = to_visit.front();
            to_visit.pop();

            for (int next = 0; next < N; next++) {
                if (cur == next || g[cur][next] == 0) continue;
                if (dist[next] > dist[cur] + 1) {
                    dist[next] = dist[cur] + 1;
                    to_visit.push(next);
                }
            }
        }

        for (const int i : dist)
            cnt[s] += i;
    }

    int ans = N, ans_cnt = cnt.back();
    for (int i = N - 2; i >= 0; i--) {
        if (ans_cnt >= cnt[i]) {
            ans = i + 1;
            ans_cnt = cnt[i];
        }
    }

    cout << ans;

    return 0;
}