#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 매 시행마다 3개씩 짝지어 중앙값만을 남길 때
 * 결국 최대 값은 오름차순 정렬후 2번째로 큰 값이 됨은 자명하다
 * 그 과정을 아래와 같은 수열로 예시를 들어본다
 *
 * 1 2 3 4 5 6 7
 * 2 4 5 6 7
 * 4 6 7
 * 6
 *
 * 따라서 앞에서부터 3개의 수들을 선택하고 소거하면서
 * 각 중앙값을 다음 상태의 가장 작은 값으로 전이시키면 된다
 */

int N;
vector<int> vec;

void init(){
    cin >> N;
    vec.resize(N);
    for(int& i : vec) cin >> i;
}

void solve(){
    if(N == 1){
        cout << vec[0];
        return;
    }

    sort(vec.begin(), vec.end(), std::less<int>());
    cout << vec[N - 2] << '\n';
    int head = vec[0], tail = vec[2];
    for(int mid = 1; mid + 1 < N; mid += 2){
        tail = vec[mid + 1];
        cout << head << ' ' << vec[mid] << ' ' << tail << '\n';
        head = vec[mid];
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
