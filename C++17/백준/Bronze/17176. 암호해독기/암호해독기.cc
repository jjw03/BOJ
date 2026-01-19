#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
string str;
int cnt[27];

void init() {
    cin >> N;
    for (int i = N; i > 0; --i) {
        int in;
        cin >> in;
        ++cnt[in > 26 ? in - 26 : in];
    }
    cin.ignore();
    getline(cin, str);
}

void solve() {
    bool is_ok = true;
    for (const char& ch : str) {
        if (ch == ' ')
            is_ok &= (--cnt[0] >= 0);
        else
            is_ok &= (--cnt[toupper(ch) - 'A' + 1] >= 0);
    }
    cout << (is_ok ? ('y') : ('n'));
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
