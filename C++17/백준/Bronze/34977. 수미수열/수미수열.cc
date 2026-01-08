#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<int> vec;

void init() {
    cin >> N;
    vec.resize(N);
    for (int& i : vec)
        cin >> i;
}

void solve() {
    bool is_ok = false;
    for (int length = 1; !is_ok && length <= N / 2; ++length) {
        int a = 0, b = N - length;
        is_ok = true;
        for (int w = 0; w < length; ++w) {
            if (vec[a] != vec[b]) {
                is_ok = false;
                break;
            }
        }
    }
    cout << (is_ok ? ("yes") : ("no"));
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}