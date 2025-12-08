#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 소인수분해가 log scale로 이루어지므로
* O(N*lg(k_i))
*/

const int MAX = 5'000;
int N;
int is_prime[MAX + 1];
vector<int> prime, num;

void init() {
    cin >> N;
    fill(&is_prime[2], &is_prime[MAX], 1);

    for (int i = 2; i <= MAX; i++) {
        if (!is_prime[i]) continue;
        prime.push_back(i);
        for (int k = 2; k * i <= MAX; k++)
            is_prime[i * k] = 0;
    }

    num.resize(N);
    for (int& i : num) cin >> i;
}

void solve() {
    for (int& n : num) {
        if (n <= MAX && is_prime[n]) 
            cout << n;
        else {
            for (const int& d : prime) {
                if (d * d > n) break;
                while (n % d == 0) {
                    cout << d << ' ';
                    n /= d;
                }
            }

            if (n > 1) cout << n;
        }
        cout << '\n';
    }
}

int main() {
    FAST_IO;
   
    init();
    solve();

    return 0;
}