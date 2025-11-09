#include <bits/stdc++.h>
using namespace std;

/*
* 정렬 + 투 포인터
* 계속 연속된 것만 찾아서 틀림..............................
* ㅆ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ㅃ!!!!!!!!!!!!!!!!!!!!!!!!!
*/

int two_pointer(const vector<int>& weight, const int C, const int ban_idx = -1) {
    int ret = 0;
    int base = 0;
    if (ban_idx != -1) base = weight[ban_idx];

    int left = 0, right = weight.size() - 1;

    while (left <= right) {
        if (left == ban_idx) left++;
        if (right == ban_idx) right--;

        int cur_weight = (left != right ? weight[left] + weight[right] : weight[left]);
        if (base + cur_weight == C) {
            ret = 1;
            break;
        }

        if (base + cur_weight < C) {
            left++;
        }
        else {
            right--;
        }
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, C, ans = 0;
    cin >> N >> C;

    vector<int> weight(N);
    for (int& i : weight) {
        cin >> i;
        // 1개만 골라도 C가 충족
        if (i == C) ans = 1;
    }
    sort(weight.begin(), weight.end(), std::less<int>());

    // 2개를 골라야 C가 충족
    if (!ans) {
        ans = two_pointer(weight, C);
    }

    // 3개를 골라야 C가 충족
    if (!ans) {
        for (int i = 0; i < N; i++)
            ans |= two_pointer(weight, C, i);
    }

    cout << ans;

    return 0;
}
