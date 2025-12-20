#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 한 종류의 옷의 개수가 나머지 모든 옷들의 총합보다 크다면
 * 해당 조합은 불가능한 조합이다
 */

ull s = 0;
int N;
vector<int> vec;

void init(){
    cin >> N;
    vec.resize(N);
    for(int& i : vec){
        cin >> i;
        s += i;
    }
}

void solve(){
    bool is_happy = true;
    for(const int& i : vec){
        ull t = i;
        is_happy &= (t <= s - i);
    }
    cout << ((is_happy || (N == 1 && vec.front() == 1)) ? ("Happy") : ("Unhappy"));
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
