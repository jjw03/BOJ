#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;

void init() {
    cin >> N;
}

void solve() {
    // cur: i + 1번째 단계에서 생긴 선의 개수
    // prv: i번째 단계까지 생긴 선의 누적 개수
    int cur = 1, prv = 0;

    // i = 1 -> N; prv에 누적하여 선 개수를 저장함
    for (int i = 1; i <= N; ++i) {
        prv += cur;
        cur *= 2;
    }

    // (기본 점 개수) + (꼭짓점을 제외한 최외각 변 위에 점 개수) * 4 + (내부 교점 개수)
    int ans = 4 + prv * 4 + prv * prv;
    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
