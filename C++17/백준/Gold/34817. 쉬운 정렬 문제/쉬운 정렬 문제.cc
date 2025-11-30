#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
    FAST_IO;
    
    int N, K;
    cin >> N >> K;

    vector<int> vec(N);
    for (int& i : vec) cin >> i;

    bool is_ok = true;
    int max_val = vec.front();
    for (int i = 1; i < N; i++) {
        if (vec[i] == max_val) continue;

        if (vec[i] > max_val) max_val = vec[i];
        else if (max_val - vec[i] > K) {
            is_ok = false;
            break;
        }
    }

    cout << (is_ok ? ("YES") : ("NO"));

    return 0;
}