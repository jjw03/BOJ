#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int sz = 100'000;
int tree[sz * 4 + 1], leaf_idx[sz + 1], original[sz + 1];
int N;

int init_tree(int s, int e, int cur = 1){
    if(s == e){
        leaf_idx[s] = cur;
        return tree[cur] = s;
    }

    int mid = (s + e) / 2;
    int left = init_tree(s, mid, cur << 1);
    int right = init_tree(mid + 1, e, cur << 1 | 1);
    
    int ret;
    if(original[left] <= original[right])
        ret = left;
    else
        ret = right;

    return tree[cur] = ret;
}

void update(int i, int v){
    original[i] = v;
    
    for(int cur = leaf_idx[i] / 2; cur > 0; cur /= 2){
        int left = tree[cur << 1], right = tree[cur << 1 | 1];
        if(original[left] < original[right])
            tree[cur] = left;
        else if(original[left] > original[right])
            tree[cur] = right;
        else
            tree[cur] = min(left, right);
    }
}

int search(const int& i, const int& j, int s, int e, int cur = 1){
    if(e < i || j < s) return 0;
    if(i <= s && e <= j) return tree[cur];

    int mid = (s + e) / 2;
    int left = search(i, j, s, mid, cur << 1);
    int right = search(i, j, mid + 1, e, cur << 1 | 1);

    if(original[left] < original[right])
        return left;
    else if(original[left] > original[right])
        return right;
    else
        return min(left, right);
}

void init(){
    cin >> N;

    for(int i = 1; i <= N; ++i){
        cin >> original[i];
    }

    original[0] = 1e9 + 1;

    init_tree(1, N);
}

void solve(){
    int M;
    cin >> M;

    while(M--){
        int q, i, v;
        cin >> q >> i >> v;
        
        if(q == 1){
            update(i, v);
        }
        else{
            cout << search(i, v, 1, N) << '\n';
        }
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
