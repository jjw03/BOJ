#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

string A, B;

void init() {
    cin >> A >> B;
}

void solve() {
    string min_A = A, max_A = A;
    string min_B = B, max_B = B;

    for (int i = 0; i < A.size(); ++i) {
        if (min_A[i] == '6')
            min_A[i] = '5';
        if (max_A[i] == '5')
            max_A[i] = '6';
    }

    for (int i = 0; i < B.size(); ++i) {
        if (min_B[i] == '6')
            min_B[i] = '5';
        if (max_B[i] == '5')
            max_B[i] = '6';
    }

    int min_ans = stoi(min_A) + stoi(min_B);
    int max_ans = stoi(max_A) + stoi(max_B);

    cout << min_ans << " " << max_ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
