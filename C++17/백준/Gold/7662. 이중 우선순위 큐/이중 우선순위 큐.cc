#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int tt;

void init(){
    cin >> tt;
}

void solve(){
    while(tt--){
        int q;
        cin >> q;
        
        multiset<int> s;
        while(q--){
            char type;
            int val;
            cin >> type >> val;
            if(type == 'I')
                s.insert(val);
            else if(!s.empty()){
                if(val == -1)
                    s.erase(s.begin());
                else
                    s.erase(--s.end());
            }
        }

        if(s.empty())
            cout << "EMPTY\n";
        else
            cout << *(--s.end()) << " " << *(s.begin()) << '\n';
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
