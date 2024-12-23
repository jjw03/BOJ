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
    for (int i = tt; i > 0; i--) {
        string s = "";
        for (int k = 1; k < i; k++) s.push_back(' ');
        s += "*";
        char p = (i == 1) ? '*' : ' ';
        for (int k = 0; k < 2 * (tt - i) - 1; k++) s.push_back(p);
        if (i != tt) s += "*";
        out.push_back(s);
    }
    for (const auto& i : out) cout << i << '\n';

    return 0;
}