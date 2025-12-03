#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 어떤 수 K가 가장 많이 등장하도록 하려면
 * 1. 수열의 가운데에 가까워야하고
 * 2. 가까운 범위내에 자신보다 큰 수가 없어야한다
 */

const int sz = 150'000;
void inorder_traversal(int cur = 1){
    if(cur > sz) return;

    inorder_traversal(cur << 1);
    cout << sz - (cur - 1) << ' ';
    inorder_traversal(cur << 1 | 1);
}

int main(){
    FAST_IO;
    
    inorder_traversal();

    return 0;
}
