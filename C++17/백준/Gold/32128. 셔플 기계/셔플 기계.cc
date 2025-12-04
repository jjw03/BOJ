#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 각 셔플 방식은 하나의 successor graph로 볼 수 있다
* 따라서 각 graph에서 노드들의 k번째 successor를 구하면 답을 알 수 있다
* 
* k번째 successor를 log scale로 구하는 방법을 희소배열이라고도 표현하는 것 같다
*/

const int bit_size = 32;
int N, M, K;

vector<vector<vector<int>>> sparse_table;

void init() {
    cin >> N >> M >> K;
    sparse_table.resize(M, vector<vector<int>>(bit_size, vector<int>(N)));

    for (int i = 0; i < M; i++) {
        vector<int> vec(N);
        for (int& i : vec) cin >> i;

        //sparse table 생성(i번째 셔플에 대하여)

        //각 정점에서 1번 이동하였을 때
        for (int k = 0; k < N; k++)
            sparse_table[i][0][k] = vec[k] - 1;

        // 2^p 만큼 이동하였을 때
        for (int p = 1; p < bit_size; p++) {
            for (int node = 0; node < N; node++) {
                // 현재 노드에서 2^(p-1)만큼 이동한 노드
                int prv = sparse_table[i][p - 1][node];

                // 현재 노드에서 2^p만큼 이동한 노드는
                // 2^(p-1)만큼 이동한 노드에서 다시 2^(p-1)만큼 이동하면 됨
                // 2^p = 2^(p-1) + 2^(p-1) = 2^(p - 1 + 1)
                sparse_table[i][p][node] = sparse_table[i][p - 1][prv];
            }
        }
    }

}

/*
* node에서 move만큼 움직인 결과는 다음과 같이 계산된다
* move를 이진수로 나타내면 각각의 1-bit 만큼 이동한 결과가 누적된 것으로 볼 수 있으므로
* 각 1-bit 마다 temporal node를 이동시켜 결과를 계산한다
* 예를 들어 move = 13일 때 13 = 8 + 4 + 1 = 1101 이고,
* (((node에서 8번 이동한 결과)에서 4번 이동한 결과)에서 1번 이동한 결과)
* 와 같이 계산한다
*/
int query(const int& idx, int node, int move) {
    int ret = node;
    for (int b = bit_size - 1; b >= 0; b--) {
        // 1-bit 마다 노드를 이동한다
        if (move & (1 << b))
            ret = sparse_table[idx][b][ret];
    }
    return ret;
}

int main() {
    FAST_IO;

    init();

    vector<int> seq(N);
    for (int i = 1; i <= N; i++)
        seq[i - 1] = i;

    while (K--) {
        int type, n;
        cin >> type >> n;

        vector<int> moved(N);
        for (int i = 0; i < N; i++) {
            //각 쿼리는 배열의 기존 요소들이 어느 자리로 가야하는지 계산한다
            moved[query(type - 1, i, n)] = seq[i];
        }

        seq.swap(moved);
    }

    for (const int& i : seq) cout << i << ' ';

    return 0;
}
