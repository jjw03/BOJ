#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* X: 순방향, Y: 역방향(inversion)
* 쉽게 풀어쓰자면 두 문자 a_i, a_j가 있을 때
* a_i - a_j < 0이라면 X++
* a_i - a_j > 0이라면 Y++
* 
* 어떤 문자 c를 이어 붙일 때 마지막 문자 k에 대하여
* 변동값이 달라진다
* 
* 모든 문자는 딱 1번씩만 등장해야 하므로
* X와 Y를 1단위로 조정할 수 있음을 알 수 있다
*/


int main() {
    FAST_IO;
    
    int N;
    string str;
    cin >> N >> str;

    int X = 0, Y = 0;
    vector<int> cnt(26, 0);
    cnt[str[0] - 'A'] = 1;

    for (int i = 1; i < N; i++) {
        if (str[i - 1] < str[i]) X++;
        else Y++;
        cnt[str[i] - 'A'] = 1;
    }

    while (abs(X - Y) > 1) {
        if (X < Y) {
            int ch = str.back() - 'A';
            for (int i = 1; i <= 26; i++) {
                int idx = (ch + i) % 26;
                if (cnt[idx]) continue;
                ch = idx;
                cnt[ch] = 1;
                break;
            }
            str.push_back(ch + 'A');
        }
        else {
            int ch = str.back() - 'A';
            for (int i = 1; i <= 26; i++) {
                int idx = (ch - i + 26) % 26;
                if (cnt[idx]) continue;
                ch = idx;
                cnt[ch] = 1;
                break;
            }
            str.push_back(ch + 'A');
        }

        if (str[str.size() - 2] < str[str.size() - 1])
            X++;
        else
            Y++;
    }

    cout << str.size() << endl << str;

    return 0;
}