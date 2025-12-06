#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 모든 조합으로 잘린 통나무들 중 가장 긴 통나무의 길이의 최솟값을 l이라 하자
 * 어떠한 조합으로 통나무를 자르더라도 그 중 최대길이는 항상 [l, L]의 범위 내에 있다
 * 
 * 그렇다면 통나무를 자르는 조합들을 임의의 길이 k 이하가 되도록 제한한다고 가정하자
 * 통나무를 자르는 행위는 다음의 방법을 따른다
 *
 * 현재까지 자르지 않고 지나온 통나무들의 누적 길이를 x라고 정의하면
 * x <= k일 경우: 다음 통나무 조각을 현재 통나무들에 이어 붙인다
 * x > k일 경우: 원하지 않는 조합이므로 마지막으로 붙은 조각을 잘라낸다
 */

int main(){
    FAST_IO;

    int L, K, C;
    cin >> L >> K >> C;

    set<int> s;
    while(K--){
        int p;
        cin >> p;
        s.insert(p);
    }

    //구간 길이 계산 편의를 위해 0 ~ L로 pos를 구성
    vector<int> pos = {0};
    for(auto iter = s.begin(); iter != s.end(); iter++)
        pos.push_back(*iter);
    if(pos.back() < L) pos.push_back(L);

    //parametric search
    int a = 0, b = L, cut = pos[1];
    while(a <= b){
        int l = (a + b) / 2;
        int idx = pos.size() - 1, prv = pos.size() - 1, cnt = C;
        while(idx >= 0 && cnt > 0){
            int t = pos[prv] - pos[idx];
            
            //가능한 길이일 경우 구간 길이 증가
            if(t <= l){
                idx--;
            }
            //불가능할 경우 이전 구간 종료 및 cnt 감소
            else{
                prv = idx + 1;
                cnt--;
            }
        }

        //불가능한 l
        if(idx >= 0 && l < pos[prv]){
            a = l + 1;
        }
        //가능한 l
        else{
            b = l - 1;
            
            //마지막 loop(a = b 시점) 에서는 t = l을 충족하는 cut point가 존재함
            //따라서 cut = pos[prv]로 가장 처음 자르는 위치를 저장할 수 있음
            //만약 자르는 횟수가 남았다면 가장 처음 통나무를 더 쪼갤 수 있다는 의미이므로
            //가장 첫 포지션에서 자르면 됨
            cut = cnt > 0 ? pos[1] : pos[prv];
        }
    }

    cout << a << ' ' << cut;

    return 0;
}
