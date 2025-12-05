#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 최대 거리를 구하는 문제이므로 매개변수 탐색으로 찾음
 * 문제에서 요구하는 최댓값 M이 존재할 것이고
 * 해당 M을 초과하는 거리에 대해서는 모든 공유기를 설치할 수 없으므로
 * 결정문제로 치환됨
 *
 * 최댓값 M을 찾는 과정은 이분탐색으로 구현하면
 * lg(1e9) 이므로 각 과정마다 200'000개의 배열을 모두 탐색하여도 TLE가 아님
 * 따라서 시간복잡도는 O(N*lg(1e9))
 */

int N, C;

int main(){
    FAST_IO;

    cin >> N >> C;

    vector<int> pos(N);
    for(int& i : pos) cin >> i;
    sort(pos.begin(), pos.end(), std::less<int>());

    int a = 0, b = 1e9;
    while(a <= b){
        int mid = (a + b) / 2;
        int cnt = C - 1, prv = 0;
        for(int i = 1; i < N && cnt > 0; i++){
            if(pos[i] - pos[prv] >= mid){
                prv = i;
                cnt--;
            }
        }

        //충족 가능한 길이
        if(cnt == 0){
            a = mid + 1;
        }
        //충족 불가능한 길이
        else{
            b = mid - 1;
        }
    }

    //항상 최종형태는 a = b + 1의 형태가 된다
    //종료 조건은 b < a인 시점이므로 아래와 같이 답을 구할 수 있다
    //case 1: 마지막 mid값을 충족하면서 배치가 가능한 경우
    //a = mid + 1 이므로 a = b 시점에서 a가 가능한 범위를 벗어난다, 따라서 답은 b
    //case 2: 마지막 mid값으로는 배치가 불가능한 경우
    //b = mid - 1 이므로 a = b 시점에서 b가 가능한 최댓값의 위치로 조정된다, 따라서 답은 b
    cout << b;

    return 0;
}
