#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 원점을 가로질러서 가는 행위는 항상 손해이다
* 즉 같은 방향으로 가는 책들만 한번에 옮겨야한다
* 
* 두 방향 중 어떤 책을 마지막으로 가져다 놓아야하는가?
* + 방향의 max값을 a, - 방향의 max값을 b라 하자(절대값)
* a, b 둘 중 더 큰 값의 방향의 책을 마지막에 갖다 놓는것이 최소값이 된다
*/

int N, M;
vector<int> positive, negative;

void init() {
    cin >> N >> M;
    positive.reserve(N);
    negative.reserve(N);

    for (int i = 0; i < N; i++) {
        int in; cin >> in;
        if (in > 0)
            positive.push_back(in);
        else
            negative.push_back(-in);
    }

    sort(positive.begin(), positive.end(), std::less<int>());
    sort(negative.begin(), negative.end(), std::less<int>());
}

void solve() {
    int p_sum = 0, n_sum = 0;
    int p = positive.size() - 1, n = negative.size() - 1;

    if (p < 0) positive.push_back(0);
    if (n < 0) negative.push_back(0);

    //두 방향으로 모두 왕복하는 최솟값을 구함
    //가장 먼 책들부터 뭉탱이로 놓으면 최솟값이됨
    while (p >= 0) {
        p_sum += positive[p] * 2;
        p -= M;
    }

    while (n >= 0) {
        n_sum += negative[n] * 2;
        n -= M;
    }

    //두 방향중 더 멀리 있는 책을 마지막으로 가져다 놓음
    cout << p_sum + n_sum - max(positive.back(), negative.back());
}

int main() {
    FAST_IO;
   
    init();
    solve();

    return 0;
}