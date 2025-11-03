#include <bits/stdc++.h>
using namespace std;

/*
* 각 열에 대해 아래방향으로 누적합을 구하고
* 오른쪽 방향으로 계단식 누적합을 구하면 O(NM + Q)
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> fish(N, vector<int>(M));
    for (vector<int>& v : fish) {
        for (int& i : v) cin >> i;
    }

    //prefix sum
    //by column
    for (int row = 1; row < N; row++) {
        for (int col = 0; col < M; col++)
            fish[row][col] += fish[row - 1][col];
    }

    //by stair shape
    for (int row = 1; row < N; row++) {
        for (int col = 1; col < M; col++)
            fish[row][col] += fish[row - 1][col - 1];
    }

    //query
    while (Q--) {
        int w, p;
        cin >> w >> p;
        cout << fish[w - 1][p - 1] << '\n';
    }


    return 0;
}
