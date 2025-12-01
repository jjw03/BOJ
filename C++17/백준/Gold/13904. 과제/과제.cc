#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

//설명은 2109번 코드 참조

struct subject{
    int deadline;
    int score;
    subject(int deadline = 0, int score = 0)
        : deadline(deadline), score(score) {}
};

namespace cmp{
    struct cmp_deadline{
        bool operator()(const subject& a, const subject& b) const {
            if(a.deadline != b.deadline) return a.deadline > b.deadline;
            return a.score > b.score;
        }
    };

    struct cmp_score{
        bool operator()(const subject& a, const subject& b) const {
            if(a.score != b.score) return a.score > b.score;
            return a.deadline > b.deadline;
        }
    };
}

int main(){
    FAST_IO;

    int n;
    cin >> n;
    
    priority_queue<subject, vector<subject>, cmp::cmp_deadline> pq1;
    while(n--){
        int d, s;
        cin >> d >> s;
        pq1.push({d, s});
    }

    int d = 1;
    priority_queue<subject, vector<subject>, cmp::cmp_score> pq2;
    while(!pq1.empty()){
        if(d <= pq1.top().deadline){
            pq2.push(pq1.top());
            d++;
        }
        else if(pq1.top().score > pq2.top().score){
            pq2.pop();
            pq2.push(pq1.top());
        }
        pq1.pop();
    }

    int ans = 0;
    while(!pq2.empty()){
        ans += pq2.top().score;
        pq2.pop();
    }
    cout << ans;

    return 0;
}
