#include <bits/stdc++.h>
using namespace std;

/*
* 각 논을 하나의 노드로 가정하면 완전 연결 그래프를 만들 수 있고
* 모든 논에 물을 대는 것은 해당 그래프의 MST를 구하는 것과 같다
* 
* 따라서 초기에는 모든 논에 우물을 팠다고 가정하고 분리집합을 생성후
* 각 분리집합들을 잇는 경우와 잇지 않고 유지하는 경우의 비용을 비교하여
* 최솟값을 찾으면 답
*/

vector<int> parent;
vector<int> cost;       //우물을 파는 비용
vector<int> group_cost; //각 분리집합의 합계비용
int ans = 0;

int find_root(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

//x becomes y's parent
void union_root(int x, int y) {
    int root_x = find_root(x), root_y = find_root(y);
    parent[root_y] = root_x;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    parent.resize(N);
    for (int i = 0; i < N; i++) parent[i] = i;

    cost.resize(N);
    group_cost.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        ans += cost[i];
        group_cost[i] = cost[i];
    }

    vector<vector<int>> g(N, vector<int>(N));
    for (vector<int>& v : g) {
        for (int& i : v)
            cin >> i;
    }

    //MST
    struct edge {
        int a;
        int b;
        int cost;

        edge(int a, int b, int cost) : a(a), b(b), cost(cost) {}

        bool operator<(const edge& other) const {
            if (other.cost != cost) return other.cost < cost;
            if (other.a != a) return other.a < a;
            return other.b < b;
        }
    };

    priority_queue<edge> pq;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (i == k) continue;
            pq.push(edge(i, k, g[i][k]));
        }
    }

    while (!pq.empty()) {
        const edge cur = pq.top();
        pq.pop();

        int root_a = find_root(cur.a), root_b = find_root(cur.b);
        if (root_a == root_b) continue;

        int new_group_cost = group_cost[root_a] + group_cost[root_b] + cur.cost - max(cost[root_a], cost[root_b]);

        //case 1: group_a + group_b < concatenate
        if (group_cost[root_a] + group_cost[root_b] < new_group_cost)
            continue;
        //case 2: group_a + group_b >= concatenate
        else {
            ans += cur.cost - max(cost[root_a], cost[root_b]);

            int p = cost[root_a] < cost[root_b] ? root_a : root_b;
            int c = cost[root_a] < cost[root_b] ? root_b : root_a;

            union_root(p, c);
            group_cost[p] = new_group_cost;
        }
    }

    cout << ans;

    return 0;
}
