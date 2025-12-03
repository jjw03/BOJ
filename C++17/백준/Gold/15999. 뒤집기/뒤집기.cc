#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 격자판의 색이 한번 변하면 동일한 색의 타일들과 연결된다
 * 따라서 특정 색의 영역은 격자판을 누를 수록 계속해서 증가하고
 * 격자판을 누르는 횟수에 제한이 없으므로
 * 현재 상태의 격자판에서 각 영역 내부의 타일 개수만큼 경우의 수를 세면 된다
 * 각 영역의 내부 타일(테두리를 제외한 타일들)의 수를 세고
 * 2의 제곱수 만큼의 경우의 수를 구하면 된다
 */

const ll divisor = (ll)1e9 + 7;
int N, M;

vector<vector<int>> _map, area;   //0: black, 1: white
vector<ll> cnt;

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void init(){
    cin >> N >> M;

    _map.resize(N, vector<int>(M, 0));
    area.resize(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int k = 0; k < M; k++)
            _map[i][k] = (s[k] == 'W');
    }
}

inline bool in_bound(int x, int y){
    return (0 <= x && x < N) && (0 <= y && y < M);
}

//BFS로 군집화 및 개수 세기
ll BFS(pair<int, int> s, const int idx){
    ll cnt_area = 0;
    queue<pair<int, int>> to_visit;
    to_visit.push(s);
    area[s.first][s.second] = idx;

    while(!to_visit.empty()){
        auto [x, y] = to_visit.front();
        to_visit.pop();

        bool is_inner_area = true;
        for(const auto& [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(!in_bound(nx, ny)) continue;

            if(_map[x][y] != _map[nx][ny]){
                is_inner_area = false;
                continue;
            }

            if(area[nx][ny] == 0) {
                area[nx][ny] = idx;
                to_visit.push({nx, ny});
            }
        }

        if(is_inner_area) cnt_area++;
    }

    return cnt_area;
}

//각 영역의 내부 개수 세기
void make_group(){
    int idx = 1;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(area[x][y] == 0){
                cnt.push_back(BFS({x, y}, idx++));
            }
        }
    }
}

//2의 제곱 분할 정복
ll powered(int p){
    if(p == 0) return 1;
    if(p == 1) return 2;

    if(p % 2 == 0){
        ll ret = powered(p >> 1);
        return ((ret % divisor) * (ret % divisor)) % divisor;
    }
    else{
        ll ret = powered(p >> 1);
        return (((ret % divisor) * (ret % divisor)) % divisor) << 1;
    }
}

//가능한 초기 상태의 개수를 계산
//1. 각 영역에서 가능한 경우의 수 계산(2^(cnt))
//2. 영역 간에 가능한 조합 계산(product)
ll calc_ivp(){
    //1번
    vector<ll> powered_set(cnt.size());
    for(int i = 0; i < cnt.size(); i++){
        powered_set[i] = powered(cnt[i]);
    }

    //2번
    ll ret = powered_set.front();
    for(int i = 1; i < cnt.size(); i++)
        ret = ((ret % divisor) * (powered_set[i] % divisor)) % divisor;

    return ret;
}

int main(){
    FAST_IO;

    init();
    make_group();

    ll ans;
    if(cnt.empty()) ans = 0;
    else ans = calc_ivp();
    cout << ans;

    return 0;
}