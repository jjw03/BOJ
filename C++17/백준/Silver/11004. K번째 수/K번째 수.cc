#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N, K;
vector<int> vec;

void init(){
    cin >> N >> K;
    vec.resize(N);
    for(int& i : vec) cin >> i;
}

void solve(){
    sort(vec.begin(), vec.end(), std::less<int>());
    cout << vec[K - 1];
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
