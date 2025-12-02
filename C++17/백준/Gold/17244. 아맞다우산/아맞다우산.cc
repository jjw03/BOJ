#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 각 물건들, 사람 사이의 최단거리를 구하고 그래프로 나타낸 다음
* 사람 - 출구의 최단거리를 플로이드-워셜로 구하기
*/

int N, M;
int _map[50][50];
int start_idx, exit_idx;
vector<pair<int, int>> bfs_start;
vector<vector<int>> graph;

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void init() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int k = 0; k < M; k++) {
            switch (str[k]) {
            case '#':
                _map[i][k] = -1;
                break;
            case 'X':
                bfs_start.push_back({ i, k });
                break;
            case 'S':
                start_idx = bfs_start.size();
                bfs_start.push_back({ i, k });
                break;
            case 'E':
                exit_idx = bfs_start.size();
                bfs_start.push_back({ i, k });
                break;
            default:
                break;
            }
        }
    }

    graph.resize(bfs_start.size(), vector<int>(bfs_start.size(), 0));
}

inline bool in_bound(int x, int y) {
    return (0 <= x && x < N) && (0 <= y && y < M);
}

//각 지점들 간의 최단거리 계산
void BFS(int s_idx) {
    pair<int, int> s = bfs_start[s_idx];
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    dist[s.first][s.second] = 0;

    queue<pair<int, int>> to_visit;
    to_visit.push(s);

    while (!to_visit.empty()) {
        auto [x, y] = to_visit.front();
        to_visit.pop();

        for (const auto& [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (!in_bound(nx, ny) || _map[nx][ny] == -1) continue;

            int d = dist[x][y] + 1;
            if (dist[nx][ny] > d) {
                dist[nx][ny] = d;
                to_visit.push({ nx, ny });
            }
        }
    }

    for (int i = 0; i < bfs_start.size(); i++) {
        if (i == s_idx) continue;
        auto [x, y] = bfs_start[i];
        graph[s_idx][i] = dist[x][y];
    }
}

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    }
};

// 물건을 모두 챙기고 E로 가는 최단거리(완전 탐색)
int shortest_path(vector<int> path, int mask, int cur) {
    mask |= (1 << (cur + 1));
    path.push_back(cur);

    if (path.size() == bfs_start.size() - 1) {
        int ret = graph[exit_idx][path.back()];
        for (int i = path.size() - 1; i - 1 >= 0; i--)
            ret += graph[path[i]][path[i - 1]];
        return ret;
    }

    int ret = INT_MAX;
    for (int next = 0; next < bfs_start.size(); next++) {
        if (next == cur || next == exit_idx) continue;
        if (mask & (1 << (next + 1))) continue;

        ret = min(ret, shortest_path(path, mask, next));
    }

    return ret;
}

int main() {
    FAST_IO;

    init();

    //make graph
    for (int i = 0; i < bfs_start.size(); i++)
        BFS(i);

    //calculate shortest path
    cout << shortest_path({}, 0, start_idx);

    return 0;
}
