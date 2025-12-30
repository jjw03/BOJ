#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 나는 똥멍청이
* https://rebro.kr/60
*/

int N;

struct pos {
    int x;
    int y;
    pos(int x = 0, int y = 0)
        : x(x), y(y) { }
};

vector<int> add, sub;

void init() {
    cin >> N;

    while(N--) {
        int x, y;
        cin >> x >> y;
        add.push_back(x + y);
        sub.push_back(x - y);
    }
}

void solve() {
    sort(add.begin(), add.end());
    sort(sub.begin(), sub.end());

    cout << max(add.back() - add[0], sub.back() - sub[0]);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}