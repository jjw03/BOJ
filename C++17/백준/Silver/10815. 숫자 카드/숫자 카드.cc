#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int offset = 10'000'000;
int cnt[(offset << 1) + 1];

int main() {
    FAST_IO;

    int N;
    cin >> N;
    while (N--) {
        int in;
        cin >> in;
        cnt[offset + in]++;
    }

    int M;
    cin >> M;
    while (M--) {
        int in;
        cin >> in;
        cout << (int)(cnt[offset + in] > 0) << '\n';
    }
    

    return 0;
}
