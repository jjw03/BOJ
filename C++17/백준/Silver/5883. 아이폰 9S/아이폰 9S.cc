#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* N <= 1000 이므로 서로다른 용량의 수도 최대 1000
* 따라서 O(1e6)
*/

int N;
set<int> type;
vector<int> storage;

void init() {
    cin >> N;
    storage.resize(N);
    for (int& i : storage) {
        cin >> i;
        type.insert(i);
    }
}

void solve() {
    int ans = 0;
    for (auto iter = type.begin(); iter != type.end(); iter++) {
        int ex = *iter, cur = storage.front();;
        int t = 0;
        for (int i = 0; i < N; i++) {
            if (storage[i] == ex) continue;

            if (storage[i] == cur) {
                t++;
            }
            else {
                cur = storage[i];
                ans = max(ans, t);
                t = 1;
            }
        }
        ans = max(ans, t);
    }
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}