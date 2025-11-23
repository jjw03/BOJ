#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
* 3의 제곱수의 합으로 표현되는 수는 다음의 수식과 같음
* a*3^0 + b*3^1 + c*3^2 + ...
* 
* 각 항의 계수는 0 또는 1의 값을 가지므로 아래와 같은 이진수로 표현이 가능함
* abc... -> 11010...
* 
* 따라서 N번째 수는 N의 이진수 값에 따라 계수를 적절히 정해주면 구할 수 있음
* 
* 또한 3^n은 3^n-1 ~ 3^0까지 모두 더한 수보다 크므로
* 동일한 값을 가지는 조합수가 존재하지 않음을 알 수 있음
* (비트 배열이 달라지면 값이 달라질 수 밖에 없음)
*/

int main() {
    FAST_IO;
    
    ll N;
    cin >> N;

    ll weight = 1, ans = 0;
    while (N > 0) {
        if (N & 1) {
            ans += weight;
        }
        weight *= 3;
        N >>= 1;
    }

    cout << ans;

    return 0;
}