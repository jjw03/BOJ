#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* N <= 2000 이라서 O(N^2)도 가능
*/

int N;
vector<int> weight, dp_front, dp_back;

void init() {
    cin >> N;

    if (N == 0) return;

    weight.resize(N);
    dp_front.resize(N); // 이전 열차의 선두에 추가
    dp_back.resize(N);  // 이전 열차의 후미에 추가

    for (int& i : weight) cin >> i;
}

void solve() {
    if (N == 0) {
        cout << 0;
        return;
    }

    // i번째 열차를 선두로 하였을 때 생성될 수 있는 최대 길이
    for (int i = N - 1; i >= 0; --i) {  // 역순 탐색
        dp_front[i] = 1, dp_back[i] = 1;
        for (int k = i + 1; k < N; ++k) {
            if (weight[i] > weight[k])
                dp_back[i] = max(dp_back[i], dp_back[k] + 1);
            if (weight[i] < weight[k])
                dp_front[i] = max(dp_front[i], dp_front[k] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans = max(ans, dp_front[i] + dp_back[i] - 1);   // 자기 자신 -1
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
