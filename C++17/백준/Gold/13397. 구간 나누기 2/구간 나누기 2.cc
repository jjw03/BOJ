#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 원하는 max - min 값을 k라고 정의하자
 * k값이 가능한지 판별하는 방법은 무엇일까?
 *
 * 어떤 구간 [a,b]의 max - min 값을 a'이라 하자
 * [a,b]의 길이가 늘어나도 a'의 값은 감소하지 않는다
 * 이 점을 이용하여 다음과 같은 방법을 고안한다
 *
 * 어떤 구간의 [a,b]가 a'값에 따라
 * a' <= k일 경우 구간의 길이를 증가시킨다
 * a' > k일 경우 구간의 길이를 1 감소시키고 새로운 구간을 생성한다
 * 이 과정을 최대 구간 개수 M을 넘지 않을 동안 반복한다
 *
 * 위의 과정을 모두 마쳤을 때 종료 시점의 인덱스 값이 N보다 작다면
 * 해당 k값은 충족 불가능한 값이다
 */

int main(){
    FAST_IO;

    int N, M;
    cin >> N >> M;
    
    int t_min = INT_MAX, t_max = 0;
    vector<int> vec(N);
    for(int& i : vec){
        cin >> i;
        t_min = min(t_min, i);
        t_max = max(t_max, i);
    }

    int a = 0, b = t_max - t_min;
    while(a <= b){
        int k = (a + b) / 2;
        int idx = 0, cnt = M;
        int val_max = 0, val_min = INT_MAX;
        while(idx < N && cnt > 0){
            int a_prime = max(val_max, vec[idx]) - min(val_min, vec[idx]);
            
            if(a_prime <= k){
                //구간을 증가시킨다
                val_max = max(val_max, vec[idx]);
                val_min = min(val_min, vec[idx]);
                idx++;
            }
            else{   //a_prime > k
                //a_prime > k의 경우에는 현재 값을 새로운 구간의 시작값으로 세팅
                cnt--;
                val_max = vec[idx];
                val_min = vec[idx];
            }
        }
        
        //불가능한 k(정확히는 k 이하의 값이 최댓값으로 등장한다는 의미)
        if(idx < N){
            a = k + 1;
        }
        //가능한 k
        else{
            b = k - 1;
        }
    }

    cout << a;

    return 0;
}
