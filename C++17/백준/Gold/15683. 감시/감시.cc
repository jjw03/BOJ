#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * cctv가 최대 8개이므로 백트래킹으로 가능
 */

int N, M, total_area = 0;
int graph[8][8];
vector<pair<int, int>> cctv;

/*
 * 아래의 방향 배열로 cctv 회전을 다음과 같이 표현 가능
 * 1번: idx로 단방향 표현, idx is 0 ~ 3
 * 2번: idx, (idx + 2) % 2 로 2방향 180도 표현, idx is 0 ~ 1
 * 3번: idx, (idx + 1) % 4 로 2방향 90도 표현, idx is 0 ~ 3
 * 4번: idx, (idx + 1) % 4, (idx + 2) % 4 로 3방향 표현, idx is 0 ~ 3
 * 5번: 모든 idx 사용, 회전 없음
 */
vector<pair<int, int>> dir = {
    {0, -1},    //left
    {-1, 0},    //up
    {0, 1},     //right
    {1, 0}      //down
};

void init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cin >> graph[i][k];
            if (graph[i][k] == 0)
                total_area++;
            else if (graph[i][k] < 6)
                cctv.push_back({ i, k });
        }
    }
}

inline bool in_bound(int x, int y) {
    return (0 <= x && x < N) && (0 <= y && y < M);
}

//가시거리 설정
void set_view(const int cctv_idx, const int dx, const int dy) {
    auto [x, y] = cctv[cctv_idx];
    int set_val = -(cctv_idx + 1);    //가시거리 회수를 위해서 unique value 설정
    x += dx, y += dy;
    while (in_bound(x, y) && graph[x][y] != 6) {
        //값을 누적함으로써 회수 시에도 중첩된 구간을 유지 가능
        if (graph[x][y] <= 0) graph[x][y] += set_val;
        x += dx, y += dy;
    }
}

//가시거리 회수
void retrieve_view(const int cctv_idx, const int dx, const int dy) {
    auto [x, y] = cctv[cctv_idx];
    int retrieve_val = cctv_idx + 1;
    x += dx, y += dy;
    while (in_bound(x, y) && graph[x][y] != 6) {
        if (graph[x][y] < 0) graph[x][y] += retrieve_val;
        x += dx, y += dy;
    }
}

//비가시 영역 세기
int count_area() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            if (graph[i][k] == 0)
                ret++;
        }
    }
    return ret;
}

//타입에 따라 시야각 방향을 반환
vector<vector<pair<int, int>>> get_dir(const int type) {
    vector<vector<pair<int, int>>> ret;
    if (type == 1) {
        for (const pair<int, int>& d : dir)
            ret.push_back({ d });
    }
    else if (type == 2) {
        ret.push_back({ dir[0], dir[2] });
        ret.push_back({ dir[1], dir[3] });
    }
    else if (type == 3) {
        for (int idx = 0; idx < 4; idx++) {
            ret.push_back({ dir[idx], dir[(idx + 1) % 4] });
        }
    }
    else if (type == 4) {
        for (int idx = 0; idx < 4; idx++) {
            ret.push_back({ dir[idx], dir[(idx + 1) % 4], dir[(idx + 2) % 4] });
        }
    }
    else {
        ret.push_back({ dir[0], dir[1], dir[2], dir[3] });
    }
    return ret;
}

int backtracking(const int cctv_idx) {
    //end case
    if (cctv_idx == cctv.size())
        return count_area();

    //rotate cctv
    vector<vector<pair<int, int>>> cctv_dir
        = get_dir(graph[cctv[cctv_idx].first][cctv[cctv_idx].second]);

    int ret = INT_MAX;
    for (const vector<pair<int, int>>& v : cctv_dir) {
        for (const auto& [dx, dy] : v) {
            set_view(cctv_idx, dx, dy);
        }
        ret = min(ret, backtracking(cctv_idx + 1));
        for (const auto& [dx, dy] : v) {
            retrieve_view(cctv_idx, dx, dy);
        }
    }

    return ret;
}

int main() {
    FAST_IO;

    init();
    if (cctv.empty()) cout << count_area();
    else cout << backtracking(0);

    return 0;
}
