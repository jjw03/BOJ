#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int tt;

void init(){
    cin >> tt;
}

void solve(){
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    while(tt--){
        int K;
        cin >> K;
        while(K--){
            ull in; cin >> in;
            pq.push(in);
        }
        
        ull ans = 0;
        while(pq.size() > 1){
            ull t = pq.top();
            pq.pop();

            t += pq.top();
            pq.pop();
            
            ans += t;
            pq.push(t);
        }

        cout << ans << '\n';
        pq.pop();
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
