#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int divisor = (int)1e9 + 7;
int n, m;
uint dp[1000][1000];

void init(){
    cin >> n >> m;
    dp[0][0] = 1;
}

vector<pair<int, int>> dir = {
    {-1, -1},
    {-1, 0},
    {0, -1}
};

inline bool in_bound(int x, int y){
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void solve(){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(x == 0 && y == 0) continue;

            for(const auto& [dx, dy] : dir){
                int px = x + dx, py = y + dy;
                if(!in_bound(px, py)) continue;

                dp[x][y] = ((dp[x][y] % divisor) + (dp[px][py] % divisor)) % divisor;
            }
        }
    }

    cout << dp[n - 1][m - 1];
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
