#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int h, w;
vector<int> height;

void init(){
    cin >> h >> w;
    height.resize(w);
    for(int& i : height) cin >> i;
}

void solve(){
    int ans = 0;
    
    //각 높이에 대해 탐색
    //벽으로 둘러 싸여 있다면 해당 영역의 넓이 추가
    for(int x = 1; x <= h; x++){
        int prv = -1;    //직전에 나온 벽 위치
        for(int i = 0; i < w; i++){
            //벽의 높이가 현재 높이보다 낮음
            if(height[i] < x) continue;
            
            //벽으로 둘러싸여 있다면 추가
            if(prv != -1)
                ans += i - prv - 1;
            
            //직전 벽 위치 갱신
            prv = i;
        }
    }

    cout << ans;
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
