#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 상하좌우로 인접한 타일들의 색상이 모두 같은 타일들을 세고
 * 2의 제곱을 구하면 된다
 */

const ll divisor = (ll)1e9 + 7;

int N, M;
int _map[2000][2000];

vector<pair<int, int>> dir ={
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void init(){
    cin >> N >> M;
    for(int x = 0; x < N; x++){
        string s;
        cin >> s;
        for(int y = 0; y < M; y++){
            _map[x][y] = (int)(s[y] == 'W');
        }
    }
}

ll powered(ll p){
    if(p == 0) return 1;
    if(p == 1) return 2;
    
    ll ret = powered(p >> 1);
    ret = ((ret % divisor) * (ret % divisor)) % divisor;
    if(p % 2 == 1){
        ret = (ret * 2) % divisor;
    }
    
    return ret;
}

inline bool in_bound(int x, int y){
    return (0 <= x && x < N) && (0 <= y && y < M);
}

bool is_inner(int x, int y){
    bool is_ok = true;
    for(const auto& [dx, dy] : dir){
        int nx = x + dx, ny = y + dy;
        if(!in_bound(nx, ny)) continue;
        if(_map[x][y] != _map[nx][ny]){
            is_ok = false;
            break;
        }
    }
    return is_ok;
}

ll count_tiles(){
    ll cnt = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(is_inner(x, y))
                cnt++;
        }
    }
    return cnt;
}

int main(){
    FAST_IO;

    init();
    ll cnt = count_tiles();
    cout << powered(cnt);

    return 0;
}
