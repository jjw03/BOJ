#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<pair<string, string>> vec;
map<string, vector<string>> cnt;

void init() {
    cin >> N;

    vec.resize(N);

    for (auto& [name, tag] : vec) {
        cin >> name >> tag;
        if (tag != "-") {
            auto iter = cnt.find(tag);
            if (iter == cnt.end())
                cnt.insert({ tag, { name } });
            else
                cnt[tag].push_back(name);
        }
    }
}

void solve() {
    vector<pair<string, string>> ans;
    for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
        const auto& [tag, v] = *iter;
        if (v.size() == 2)
            ans.push_back({ v[0], v[1] });
    }

    cout << ans.size() << '\n';
    for (const auto& [n1, n2] : ans)
        cout << n1 << ' ' << n2 << '\n';
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
