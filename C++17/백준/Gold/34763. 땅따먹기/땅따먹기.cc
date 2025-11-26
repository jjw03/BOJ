#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 각 시행의 단계 1마다 어떤 변의 0을 선택하느냐에 따라서 소거되는 변이 다르다
 * 가로방향, 세로방향으로 서로 평행한 변들은 모두 길이가 같으므로
 * 가로, 세로 중 어떤 변을 소거할 것인지만 결정하면 다음 1의 개수를 알 수 있다
 * 
 * 위의 법칙에 따라 각 n에 따른 가로, 세로 길이를 나열해 보면
 * 1: 1 1
 * 2: 1 2
 * 3: 1 3 or 2 2
 * 4: 1 4 or 2 3
 * 5: 1 5 or 2 4 or 3 3
 * 6: 1 6 or 2 5 or 3 4
 * ...
 *
 * 따라서 만들어질 수 있는 1의 개수는
 * a*(n - a), for a >= 1 임을 알 수 있다
 *
 * 그러므로 각 쿼리마다 K를 약수로 분해하고 약수의 합이 N + 1이 될 수 있는지 검토하면 답을 알 수 있다
 * O(sqrt(K)*T) = 약 O(10^5)
 */

int main(){
    FAST_IO;

    int tt;
    cin >> tt;
    while(tt--){
        int N, K;
        cin >> N >> K;

        bool is_possible = false;
        for(int i = 1; i * i <= K; i++){
            if(K % i == 0){
                is_possible |= (i + K / i == N + 1);
            }
        }
        cout << (is_possible ? ("YES") : ("NO")) << '\n';
    }

    return 0;
}
