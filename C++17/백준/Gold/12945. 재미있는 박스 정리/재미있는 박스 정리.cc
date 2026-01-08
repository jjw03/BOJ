#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 항상 최소 개수는 N / 2 이상이므로
* 투포인터를 사용하여 head는 첫 원소, tail은 중앙값에서 시작한다
* 조건을 충족하면 하나로 합치고, 충족하지 않는다면 tail을 스킵하고 다음 것을 탐색
*/

int N;
vector<int> vec;

void init() {
    cin >> N;
    vec.resize(N);
    for (int& i : vec)cin >> i;
}

void solve() {
    sort(vec.begin(), vec.end());

    int a = 0, b = N / 2, cnt = 0;
    while (a < N / 2 && b < N) {
        if (vec[a] * 2 <= vec[b]) {
            ++a, ++b, ++cnt;
        }
        else {
            ++b, ++cnt;
        }
    }

    cout << N / 2 - a + N - b + cnt;
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}