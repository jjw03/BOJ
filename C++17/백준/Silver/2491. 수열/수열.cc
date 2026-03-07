#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<int> vec, dp_asc, dp_dec;

void init(){
    cin >> N;

    vec.resize(N);
    dp_asc.resize(N);
    dp_dec.resize(N);

    for(int& i : vec) cin >> i;
}

void solve(){
    dp_asc[0] = 1;
    dp_dec[0] = 1;
    
    //asc
    for(int i = 1; i < N; ++i){
        if(vec[i] >= vec[i - 1])
            dp_asc[i] = dp_asc[i - 1] + 1;
        else
            dp_asc[i] = 1;
    }

    //dec
    for(int i = 1; i < N; ++i){
        if(vec[i] <= vec[i - 1])
            dp_dec[i] = dp_dec[i - 1] + 1;
        else
            dp_dec[i] = 1;
    }

    int ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, max(dp_asc[i], dp_dec[i]));
    cout << ans;
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
