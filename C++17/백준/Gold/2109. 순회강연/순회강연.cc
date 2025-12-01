#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 각 강연들을 날짜를 기준으로 오름차순 한 다음
 * 값을 기준으로 하는 우선순위 큐에 다시 넣으면서
 * 더 큰 값의 강연이 나올 경우 현재 큐에서 가장 작은 값의 강연을 제거하면 된다
 */

struct lecture{
    int val;
    int deadline;
    lecture(int val = 0, int deadline = 0)
        : val(val), deadline(deadline) {}
};

namespace cmp_func{
    struct cmp_deadline{
        bool operator()(const lecture& a, const lecture& b) const{
            if(a.deadline != b.deadline) return a.deadline > b.deadline;
            return a.val > b.val;
        }
    };

    struct cmp_val{
        bool operator()(const lecture& a, const lecture& b) const {
            if(a.val != b.val) return a.val > b.val;
            return a.deadline > b.deadline;
        }
    };
}

int main(){
    FAST_IO;

    int n;
    cin >> n;

    priority_queue<lecture, vector<lecture>, cmp_func::cmp_deadline> pq1;
    while(n--){
        int v, d;
        cin >> v >> d;
        pq1.push(lecture(v, d));
    }

    priority_queue<lecture, vector<lecture>, cmp_func::cmp_val> pq2;
    int d = 1;
    while(!pq1.empty()){
        //deadline 안에 있으면 정상 진행
        if(d <= pq1.top().deadline){
            pq2.push(pq1.top());
            d++;    //날짜 증가
        }
        //새로 나온 값이 기존에 진행했던 강연들 중 하나보다 값이 클 경우
        else if(pq1.top().val > pq2.top().val){
            pq2.pop();
            pq2.push(pq1.top());
        }
        //값이 이전에 했던 강연들보다 작다면 바꾸지 않음
        pq1.pop();
    }

    ll ans = 0;
    while(!pq2.empty()){
        ans += pq2.top().val;
        pq2.pop();
    }
    cout << ans;

    return 0;
}
