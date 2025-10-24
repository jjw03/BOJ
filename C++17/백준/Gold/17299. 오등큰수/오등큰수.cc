#include <bits/stdc++.h>
using namespace std;

/*
* 어떤 수에서 오큰수를 찾으려면 오른쪽 부분을 탐색해야하므로
* 모노토닉 스택을 구성해서 count값에 따라 오름차순으로 정렬하면됨
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    //ngf: i번째 수의 ngf 인덱스
    vector<int> num(N), num_count((int)1e6 + 1), ngf(N);
    for (int& i : num) {
        cin >> i;
        num_count[i]++;
    }

    stack<int> stk;
    for (int i = N - 1; i >= 0; i--) {
        while (!stk.empty() && num_count[stk.top()] <= num_count[num[i]])
            stk.pop();

        if (stk.empty()) {
            ngf[i] = -1;
            stk.push(num[i]);
        }
        else {
            ngf[i] = stk.top();
            stk.push(num[i]);
        }
    }

    for (const int i : ngf) cout << i << ' ';
    return 0;
}