#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int m, n;
vector<pair<int, int>> org, pos;
map<pair<int, int>, int> cnt;

void init() {
    cin >> m;
    org.resize(m);
    
    for (pair<int, int>& p : org)
        cin >> p.first >> p.second;

    cin >> n;
    pos.resize(n);
    for (pair<int, int>& p : pos)
        cin >> p.first >> p.second;
}

void solve() {
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            pair<int, int> p = { pos[k].first - org[i].first, pos[k].second - org[i].second };
            auto iter = cnt.find(p);
            if (iter == cnt.end())
                cnt.insert({ p, 1 });
            else
                (*iter).second++;
        }
    }

    pair<int, int> ans;
    for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
        if ((*iter).second == m) {
            ans = (*iter).first;
            break;
        }
    }

    cout << ans.first << ' ' << ans.second;
}

int main() {
    FAST_IO;
   
    init();
    solve();

    return 0;
}