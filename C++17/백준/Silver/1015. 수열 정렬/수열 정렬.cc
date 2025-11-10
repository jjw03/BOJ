#include <bits/stdc++.h>
using namespace std;

/*
* 결국 수열 P는 수열 A를 오름차순 정렬했을 때 각 수들의 인덱스가 됨
* 사전순으로 가장 앞서는 것은 tie가 발생했을 때 기존 순서를 유지하는 방향으로 만들면 됨
*/

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> num(N), cnt(1e3 + 1, 0);
    for (int& i : num) {
        cin >> i;
        cnt[i]++;
    }

    //개수 누적합
    for (int i = 1; i < cnt.size(); i++)
        cnt[i] += cnt[i - 1];

    vector<int> offset(1e3 + 1, 0);
    for (const int n : num) {
        //n의 순서는 n-1번째 수까지 누적합한 결과와 n이 몇번 등장했는지로 결정됨(사전순)
        cout << cnt[n - 1] + (offset[n]++) << ' ';
    }

    return 0;
}