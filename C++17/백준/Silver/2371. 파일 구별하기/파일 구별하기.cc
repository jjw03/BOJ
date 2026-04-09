#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<vector<int>> file;

int partition(vector<int> file_idx, int idx) {
    if (file_idx.size() == 1)
        return idx;

    map<int, vector<int>> part;
    for (const int& i : file_idx) {
        if (file[i].size() < idx + 1) continue;

        auto iter = part.find(file[i][idx]);
        if (iter == part.end())
            part.insert({ file[i][idx], {i} });
        else
            part[file[i][idx]].push_back(i);
    }

    int ret = 0;
    for (auto iter = part.begin(); iter != part.end(); ++iter) {
        ret = max(ret, partition((*iter).second, idx + 1));
    }
    return ret;
}

void init() {
    cin >> N;

    file.resize(N);

    for (auto& v : file) {
        int in;
        while (cin >> in) {
            if (in == -1) break;
            v.push_back(in);
        }
    }
}

void solve() {
    vector<int> temp(N);
    for (int i = N - 1; i >= 0; --i)
        temp[i] = i;
    cout << partition(temp, 0);
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
