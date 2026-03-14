#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
int arr[1'000'000];
set<int> sorted;

void init() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sorted.insert(arr[i]);
    }
}

void solve() {
    map<int, int> val;
    int idx = 0;
    for (auto iter = sorted.begin(); iter != sorted.end(); ++iter, ++idx) {
        if (val.find(*iter) == val.end())
            val.insert({ *iter, idx });
    }

    for (int i = 0; i < N; ++i)
        cout << val[arr[i]] << ' ';
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
