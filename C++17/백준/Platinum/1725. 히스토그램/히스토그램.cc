#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct histogram{
    uint width;
    uint height;
    histogram(uint width = 0, uint height = 0)
        : width(width), height(height) {}
};

int main(){
    FAST_IO;

    int N;
    cin >> N;

    vector<uint> hist(N);
    for(uint& i : hist) cin >> i;

    uint ans = 0;
    stack<histogram> stk;
    for(int i = 0; i < N; i++){
        uint new_w = 0;
        while(!stk.empty() && stk.top().height >= hist[i]){
            auto [w, h] = stk.top();
            stk.pop();
            new_w += w;
            ans = max(ans, new_w * h);
        }
        stk.push({new_w + 1, hist[i]});
    }

    uint t = 0;
    while(!stk.empty()){
        auto [w, h] = stk.top();
        stk.pop();
        t += w;
        ans = max(ans, t * h);
    }

    cout << ans;
    
    return 0;
}
