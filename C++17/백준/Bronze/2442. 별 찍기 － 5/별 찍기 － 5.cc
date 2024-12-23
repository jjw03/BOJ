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

    for (int i = tt; i > 0; i--) {
        int line = tt - i + 1;
        for (int k = 1; k < i; k++) cout << ' ';
        for (int k = 0; k < 2 * line - 1; k++) cout << '*';
        cout << '\n';
    }

    return 0;
}