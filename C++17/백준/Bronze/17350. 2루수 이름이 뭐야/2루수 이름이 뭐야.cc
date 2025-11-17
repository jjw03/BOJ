#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    bool anj = false;
    for (cin >> n; n--;) {
        char s[101];
        cin >> s;
        anj |= strcmp(s,"anj") == 0;
    }

    cout << "뭐야" << (anj ? (";") : ("?"));

    return 0;
}