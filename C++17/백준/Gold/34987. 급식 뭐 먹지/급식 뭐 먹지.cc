#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 맛 수치, 영양 수치 2가지 항목이 존재한다
* 이 두 항목을 하나의 수직선에 표현해보자
* 맛 수치는 음의 방향으로, 영양 수치는 양의 방향으로
* 이렇게 표현하면 다음의 정보를 알 수 있다
* 어떤 학생이 가지는 취향 (a, b)를 충족시키려면
* a + b 이상의 길이를 가지는 범위 안에 그 학생이 존재해야한다
* 
* 다시 말해서, 초기 수치 0을 중앙 기준점으로 잡고
* 해당 기준점에서 충족시킬 수 있는 학생들의 집합은
* 0을 기준으로 음의 방향 길이 a, 양의 방향 길이 b의 range 안에 있는 학생들과 같다
* 
* 어떤 range 안에 있는 학생들의 수는 누적합으로 계산한다
*/

int N, M;
vector<int> in_point, out_point;

void init() {
    cin >> N >> M;
    in_point.resize(2 * M + 1, 0);
    out_point.resize(2 * M + 1, 0);

    while (N--) {
        int a, b;
        cin >> a >> b;
        if (a + b > M) continue;
        ++in_point[M + b];
        --out_point[M - a + 1];
    }
}

void solve() {
    int ans = 0, t = 0;
    int a = 0, b = 0;

    // init
    while (b < M) {
        t += in_point[b];
        ++b;
    }

    // calculate
    while (b <= 2 * M) {
        t = t + in_point[b] + out_point[a];
        ans = max(ans, t);
        a++, b++;
    }

    cout << ans;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}