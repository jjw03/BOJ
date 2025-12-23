#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * preorder 결과를 이용하여 inorder 벡터에서 각 서브트리들의 루트 노드를 찾고
 * 해당 서브트리들을 다시 왼쪽 오른쪽 서브트리로 분할하는 과정을 거친다
 */

int tt;
int inorder_idx[1001], inorder[1001], preorder[1001];

void init(){
    cin >> tt;
}

// s, e: inorder vector index / r: preorder index(root node of subtree)
void post_order(int s, int e, int r){
    if(s >= e){
        cout << preorder[r] << ' ';
        return;
    }

    //root node in inorder vector
    int root_idx = inorder_idx[preorder[r]];
    int left = root_idx - s;
    int right = e - root_idx;

    //divide subtree range
    if(left > 0)
        post_order(s, root_idx - 1, r + 1);
    if(right > 0)
        post_order(root_idx + 1, e, r + left + 1);

    cout << preorder[r] << ' ';
}

void solve(){
    while(tt--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> preorder[i];
        }
        for(int i = 0; i < n; i++){
            cin >> inorder[i];
            inorder_idx[inorder[i]] = i;
        }
    
        post_order(0, n - 1, 0);
        cout << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
