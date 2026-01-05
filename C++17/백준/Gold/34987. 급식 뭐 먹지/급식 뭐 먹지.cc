#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 어떤 학생의 수치를 만족시키려면 a <= k_a, b <= k_b인 k_a, k_b를 택해야 한다
* (a + b > M인 학생은 어떠한 방법으로도 만족시킬 수 없으므로 제외한다)
* 주어진 M에 대하여 최대 횟수의 주문을 사용하면 항상 a + b = M이고, k_a + k_b = M을 만족한다
* a <= k_a인 k_a를 택할 때 해당 학생을 만족시킬 또다른 조건은 M - k_a >= b 이다
* 두 조건을 정리하면
* 1. a <= k_a
* 2. k_a <= M - b
* 
* 일반화 하면 a <= k <= M - b이고,
* 해당 구간에 속하는 모든 자연수 k에 대하여 해당 학생을 만족시킬 수 있다
* 
* 따라서 위의 구간을 이용하여 누적합을 구하고, 그 중 최대값이 답이 된다
*/

int N, M;
vector<int> prefix;

void init() {
    cin >> N >> M;
    prefix.resize(M + 2, 0);
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (a + b > M) continue;
        ++prefix[a];
        --prefix[M - b + 1];
    }
}

void solve() {
    int ans = prefix[0];
    for (int score = 1; score <= M; score++) {
        prefix[score] += prefix[score - 1];
        ans = max(ans, prefix[score]);
    }
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}