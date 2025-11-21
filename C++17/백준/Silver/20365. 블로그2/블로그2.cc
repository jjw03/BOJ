#include <bits/stdc++.h>
#define FASTIO cin.tie(0), ios_base::sync_with_stdio(0)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 그냥 한가지 색으로 밀어버리고
* 더 적은 수의 색을 끼워넣는게 최적임
*/

int main() {
    FASTIO;

    int N;
    cin >> N;

    string s;
    cin >> s;

    bool bit = (s.front() == 'R');
    int b = 0, r = 0;
    for (int i = 1; i < N; i++) {
        if (bit == false && s[i] == 'R') {
            bit = true;
            b++;
        }
        else if (bit == true && s[i] == 'B') {
            bit = false;
            r++;
        }
    }

    if (bit) r++;
    else b++;

    cout << 1 + min(b, r);

    return 0;
}