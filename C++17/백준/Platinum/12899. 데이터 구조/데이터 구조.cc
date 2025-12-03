#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * X <= 2e6 이므로 세그먼트 트리를 구성해 각 자연수의 개수를 저장
 */

const int MAX_SIZE = 2e6;
int N, offset;
int tree[4 * MAX_SIZE + 1];
int num_idx[MAX_SIZE + 1];

// mark leaf
void init(int s = 1, int e = MAX_SIZE, int cur = 1){
    if(s == e){
        num_idx[s] = cur;
        return;
    }
    
    int mid = (s + e) >> 1;
    init(s, mid, cur << 1);
    init(mid + 1, e, cur << 1 | 1);
}

void add(int x){
    int idx = num_idx[x];
    while(idx > 0){
        tree[idx]++;
        idx >>= 1;
    }
}

int remove(int x, int s = 1, int e = MAX_SIZE, int cur = 1){
    tree[cur]--;

    if(s == e){
        return s;
    }
    
    int left_sz = tree[cur << 1], mid = (s + e) >> 1;
    if(x <= left_sz)
        return remove(x, s, mid, cur << 1);
    else
        return remove(x - left_sz, mid + 1, e, cur << 1 | 1);
}

int main(){
    FAST_IO;

    init();

    int q;
    cin >> q;
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            add(x);
        }
        else{
            cout << remove(x) << '\n';
        }
    }

    return 0;
}
