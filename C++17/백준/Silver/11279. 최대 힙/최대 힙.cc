#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
priority_queue<int> pq;

void init(){
    cin >> N;
}

void solve(){
    while(N--){
        int q;
        cin >> q;
        if(q == 0){
            if(pq.empty())
                cout << 0;
            else{
                cout << pq.top();
                pq.pop();
            }
            cout << '\n';
        }
        else{
            pq.push(q);
        }
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
