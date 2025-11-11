#include <bits/stdc++.h>
using namespace std;

/*
* 검은 셀들을 기준으로 생각했을 때 해당 셀들을 포함하고 있는 mask가 i개의 셀이 존재하는지 check
*/

vector<pair<int, int>> dir = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 0},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    long long X, Y, N;
    cin >> X >> Y >> N;

    set<pair<int, int>> cell;
    for (int i = 0; i < N; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        cell.insert(p);
    }

    //check한 mask의 중심을 저장
    set<pair<int, int>> checked;

    vector<long long> ans(10);
    ans[0] = (X - 2) * (Y - 2);

    for (set<pair<int, int>>::iterator iter = cell.begin();
        iter != cell.end(); iter++) {

        const auto& [cx, cy] = *iter;

        for (const auto& [dx, dy] : dir) {
            pair<int, int> center = { cx + dx, cy + dy };

            if ((center.first < 2 || X <= center.first || center.second < 2 || Y <= center.second)
                || checked.find(center) != checked.end()) continue;

            int cnt_cell = 0;
            for (const auto& [dx2, dy2] : dir) {
                pair<int, int> c = { center.first + dx2, center.second + dy2 };
                if (cell.find(c) != cell.end())
                    cnt_cell++;
            }

            ans[0]--, ans[cnt_cell]++;
            checked.insert(center);
        }
    }

    for (const long long i : ans) cout << i << '\n';

    return 0;
}