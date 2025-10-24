#include <bits/stdc++.h>

#define MAX_SIZE 1e6

using namespace std;

//0-base로 구현했었는데 update 쪽 pair 계산하는 과정에서 자꾸 뻑남 shit

const long long divider = 1e9 + 7;
int original[(int)MAX_SIZE + 1];
long long tree[(int)MAX_SIZE * 4 + 1];
int leaf_idx[(int)MAX_SIZE + 1];

long long init(int s, int e, int cur = 1) {
    if (s == e) {
        leaf_idx[s] = cur;
        return tree[cur] = original[s - 1];
    }

    int mid = (s + e) / 2;
    long long left = init(s, mid, cur << 1);
    long long right = init(mid + 1, e, cur << 1 | 1);

    return tree[cur] = (left * right) % divider;
}

void update(int pos, int val) {
    int idx = leaf_idx[pos];
    tree[idx] = val;
    while (idx > 1) {
        idx >>= 1;
        //parent = (child_1 * child_2) % divider
        tree[idx] = (tree[idx << 1] * tree[idx << 1 | 1]) % divider;
    }
}

long long search(const int& left, const int& right, int s, int e, int cur = 1) {
    if (left <= s && e <= right) return tree[cur];
    if (e < left || right < s) return 1;

    int mid = (s + e) / 2;
    long long l_result = search(left, right, s, mid, cur << 1);
    long long r_result = search(left, right, mid + 1, e, cur << 1 | 1);

    return (l_result * r_result) % divider;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) cin >> original[i];
    init(1, N);

    K += M;
    while (K--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        }
        else {
            cout << search(b, c, 1, N) << '\n';
        }
    }
    return 0;
}