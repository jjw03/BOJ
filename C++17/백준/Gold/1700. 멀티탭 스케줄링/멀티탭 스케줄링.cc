#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
    FAST_IO;
    
    int N, K;
    cin >> N >> K;

    vector<int> vec(K), things(K + 1, 0);
    vector<queue<int>> pos(K + 1);
    for(int& i : vec){
        cin >> i;
        things[i]++;
        pos[i].push(&i - &vec[0] + 1);
    }

    for(int i = 1; i <= K; i++)
        pos[i].push(1000);
    
    int cost = 0, cnt = 0;
    vector<int> is_remain(K + 1, 0);
    for(const int& s : vec){
        if(is_remain[s]) {
            pos[s].pop();
            continue;
        }
        
        int pull = 0, p = pos[s].front();
        for(int cur = 1; cur <= K; cur++){
            if(!is_remain[cur]) continue;
            if(pos[cur].front() > p){
                pull = cur;
                p = pos[cur].front();
            }
        }

        if(cnt == N){
            cnt--;
            cost++;
            is_remain[pull] = 0;
        }
        
        cnt++;
        pos[s].pop();
        is_remain[s] = 1;
    }

    cout << cost;

    return 0;
}
