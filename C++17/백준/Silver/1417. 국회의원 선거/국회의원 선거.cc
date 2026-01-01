#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 가장 많은 득표수의 후보들로부터 뺏어오면 된다
 */

int N, dasom;
priority_queue<int> pq;

void init(){
    cin >> N;

    --N;
    cin >> dasom;

    while(N--){
        int in;
        cin >> in;
        pq.push(in);
    }
}

void solve(){
    int ans = 0;
    while(!pq.empty() && pq.top() >= dasom){
        ++dasom, ++ans;
        pq.push(pq.top() - 1);
        pq.pop(); 
    }

    cout << ans;
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
