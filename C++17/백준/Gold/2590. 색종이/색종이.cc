#include <bits/stdc++.h>
using namespace std;

/*
* 그리디 알고리즘
* 
* 각 색종이의 경우에
* 6cm: 혼자만 사용가능
* 5cm: 1cm와 함께 사용가능
* 4cm: 1, 2cm와 함께 사용가능
* 3cm: 1, 2, 3cm와 함께 사용가능
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> paper(6);
    for (int& i : paper)cin >> i;

    //6cm: 장당 1개의 판이 필요
    int ans = paper[5];

    //5cm
    while (paper[4]--) {
        ans++;
        paper[0] -= min(11, paper[0]);
    }

    //4cm
    while (paper[3]--) {
        ans++;
        int remain = 20;

        int cnt_two = min(5, paper[1]);
        remain -= cnt_two * 4;
        paper[1] -= cnt_two;

        paper[0] -= min(remain, paper[0]);
    }

    //3cm
    //3cm만 붙이는 경우
    if (paper[2] > 0) {
        ans += paper[2] / 4;
        paper[2] %= 4;

        //3cm + 1 or 2
        if (paper[2] > 0) {
            int remain = 36 - 9 * paper[2];

            int cnt_two = min(paper[1], paper[2] == 1 ? 5 : (paper[2] == 2 ? 3 : 1));
            remain -= cnt_two * 4;
            paper[1] -= cnt_two;

            paper[0] -= min(remain, paper[0]);

            ans++;
        }
    }

    //2cm
    //2cm만 붙이는 경우
    if (paper[1] > 0) {
        ans += paper[1] / 9;
        paper[1] %= 9;

        //2cm + 1
        if (paper[1] > 0) {
            int remain = 36 - 4 * paper[1];
            paper[0] -= min(remain, paper[0]);

            ans++;
        }
    }

    //1cm
    ans += (paper[0] / 36) + (paper[0] % 36 > 0);

    cout << ans;

    return 0;
}
