#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 각 시작 지점에서 DFS를 이용해 경로를 탐색하면서
 * 사이클이 생성되면 그 경로는 무한한 경로이다
 *
 * 이 코드에서는 역방향으로 진행하지 않고 순방향으로 진행하여 구한다.
 */

int N, M;
//cycle: dfs용 스택, cycle_path: 사이클인 경로 저장
vector<vector<int>> grid, visited, cycle, cycle_path;

vector<pair<int, int>> dir = {
    {-1, -1},
    {-1, 1}
};

inline bool in_bound(int x, int y){
    return (0 <= x && x < N) && (0 <= y && y < M);
}

/*
 * 처음 경로를 구성할 때부터 격자 그래프 자체에 사이클을 생성한다
 */
bool DFS(int x, int y){
    if(cycle[x][y] || cycle_path[x][y]){
        cycle_path[x][y] = 1;
        return true;
    }

    if(visited[x][y])
        return false;

    visited[x][y] = 1;
    cycle[x][y] = 1;

    bool ret = false;
    for(const auto& [dx, dy] : dir){
        int nx = (x + dx + N) % N, ny = y + dy;
        if(!in_bound(nx, ny)) continue;
        if(!grid[nx][ny]) continue;

        ret |= DFS(nx, ny);
    }

    if(ret) cycle_path[x][y] = 1;
    cycle[x][y] = 0;
    
    return ret;
}

void init(){
    cin >> N >> M;

    grid.resize(N, vector<int>(M, 0));  // 맨 윗줄에 종료지점을 끼워넣음
    fill(grid[0].begin(), grid[0].end(), 1);

    visited.resize(N, vector<int>(M, 0));
    cycle.resize(N, vector<int>(M, 0));
    cycle_path.resize(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int k = 0; k < M; k++)
            grid[i][k] = (s[k] != 'X');
    }
}

void solve(){
    for(int s = 0; s < M; s++)
        DFS(N - 1, s);

    queue<int> ans;
    for(int i = 0; i < M; i++){
        if(cycle_path[N - 1][i])
            ans.push(i + 1);
    }
    
    cout << ans.size() << '\n';
    while(!ans.empty()){
        cout << ans.front() << ' ';
        ans.pop();
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
