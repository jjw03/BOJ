#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct person {
    int pos;
    int isMale;

    person(int pos = 0, int isMale = 0) : pos(pos), isMale(isMale) {}
    bool operator<(const person& other) const {
        if (pos != other.pos) return pos < other.pos;
        return false;
    }
};

int main() {
    FAST_IO;

    int N;
    cin >> N;

    vector<person> vec(N);
    for (person& p : vec) {
        bool im;
        cin >> im >> p.pos;
        p.isMale = im ? 1 : -1;
    }

    sort(vec.begin(), vec.end());

    vector<int> last_idx(2e6 + 1, -1);
    int ans = 0, prefix_sum = 0, offset = 1e6;
    last_idx[offset] = 0;

    for (int i = 0; i < N; i++) {
        prefix_sum += vec[i].isMale;

        int cur_idx = prefix_sum + offset;
        if (last_idx[cur_idx] == -1) {
            last_idx[cur_idx] = i + 1;
        }
        else {
            ans = max(ans, vec[i].pos - vec[last_idx[cur_idx]].pos);
        }
    }

    cout << ans;

    return 0;
}
