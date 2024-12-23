#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <functional>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <array>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tt;
    cin >> tt;

    vector<string> out;
    for (int i = 1; i <= tt; i++) {
        string s = "";
        for (int k = 0; k < tt - i; k++) s.push_back(' ');
        for (int k = 0; k < i; k++) s.push_back('*');
        out.push_back(s);
    }
    for (const auto& i : out) cout << i << '\n';
    for (int i = tt - 2; i >= 0; i--) cout << out[i] << '\n';

    return 0;
}