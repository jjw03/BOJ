#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int N;
vector<int> A, B;

struct num{
    int n;
    int type;
    int idx;
    num(int n, int type, int idx)
        : n(n), type(type), idx(idx) {}
};

vector<num> merged;

void init(){
    cin >> N;
    A.resize(N);
    B.resize(N);
    merged.reserve(N << 1);

    for(int& i : A) cin >> i;
    for(int& i : B) cin >> i;
    
    int i_A = 0, i_B = 0;
    while(i_A < N || i_B < N){
        if(!(i_B < N) || (i_A < N && A[i_A] < B[i_B])){
            merged.push_back(num(A[i_A], 0, i_A + 1));
            i_A++;
        }
        else{
            merged.push_back(num(B[i_B], 1, i_B + 1));
            i_B++;
        }
    }
}

void solve(){
    int q;
    cin >> q;
    while(q--){
        int i, j, k;
        cin >> i >> j >> k;

        const num& cur = merged[k - 1];
        
        int ans_type, ans_num;

        int cur_cnt = (cur.type == 0 ? i : j);
        int counter_cnt = (cur.type == 0 ? j : i);
        int offset_counter = k - cur.idx;

        if(offset_counter > counter_cnt){
            int d = offset_counter - counter_cnt;
            ans_type = cur.type + 1;
            ans_num = cur.idx + d;
        }
        else if(cur.idx > cur_cnt){
            int d = cur.idx - cur_cnt;
            ans_type = (cur.type ^ 1) + 1;
            ans_num = offset_counter + d;
        }
        else{
            ans_type = cur.type + 1;
            ans_num = cur.idx;
        }

        cout << ans_type << ' ' << ans_num << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
