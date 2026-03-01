#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 배낭문제 + bit masking
 */

int N;
int dp[100][20 + 1];
vector<pair<int, int>> stat;    //first: cost, second: gain

// 각 마스킹에 따라 총합이 더 높은 마스킹을 반환
int comp(int m1, int m2){
    int v1 = 0, v2 = 0;
    
    for(int i = 1; i <= N; ++i){
        if(m1 & (1 << i))
            v1 += stat[i].second;
        if(m2 & (1 << i))
            v2 += stat[i].second;
    }

    if(v1 >= v2) return m1;
    else return m2;
}

void init(){
    cin >> N;

    stat.resize(N + 1);
    
    for(int i = 1; i <= N; ++i)
        cin >> stat[i].first;
    for(int i = 1; i <= N; ++i)
        cin >> stat[i].second;

    //배낭문제에서는 cost순 정렬이 필수
    sort(stat.begin(), stat.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
            });
}

void solve(){
    for(int remain = 0; remain < 100; ++remain){    // hp가 0이 되는 경우도 제외
        for(int i = 1; i <= N; ++i){
            if(dp[remain][i] & (1 << i)) continue;

            if(remain >= stat[i].first)
                dp[remain][i] = comp(dp[remain][i - 1], dp[remain - stat[i].first][i - 1] | (1 << i));
            else
                dp[remain][i] = dp[remain][i - 1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; ++i){
        if(dp[99][N] & (1 << i)){
            ans += stat[i].second;
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
