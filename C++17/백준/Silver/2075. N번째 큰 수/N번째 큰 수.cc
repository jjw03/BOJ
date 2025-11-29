#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * N개의 수만 오름차순 유지
 */

int main(){
    FAST_IO;

    int N;
    cin >> N;

    priority_queue<int, vector<int>, std::greater<int>> pq;
    for(int i = N * N; i > 0; i--){
        int n; cin >> n;
        if(pq.size() < N) pq.push(n);
        else{
            pq.push(n);
            pq.pop();
        }
    }
    
    cout << pq.top();

    return 0;
}
