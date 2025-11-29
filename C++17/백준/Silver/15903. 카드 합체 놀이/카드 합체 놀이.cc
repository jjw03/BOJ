#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 우선순위큐로 가장 낮은 값 2개씩 뽑아서 다시 2개 넣기
 */

int main(){
    FAST_IO;

    int n, m;
    cin >> n >> m;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(n--){
        ll in; cin >> in;
        pq.push(in);
    }

    while(m--){
        ll s = pq.top();
        pq.pop();
        s += pq.top();
        pq.pop();

        pq.push(s);
        pq.push(s);
    }

    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}
