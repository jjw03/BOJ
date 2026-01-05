#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// 플로이드-워셜로 각 노드간에 경로가 존재하는지 파악

int n, m;
int graph[26][26];

void init() {
    cin >> n;
    cin.ignore();
    while (n--) {
        string s; 
        std::getline(std::cin, s);
        int a = s[0] - 'a', b = s.back() - 'a';
        graph[a][b] = 1;
    }
}

void solve() {
    for (int k = 0; k < 26; k++) {
        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                // 기존 경로가 존재한다면 보존, 존재하지 않는다면 k를 경유하는 경로를 고려
                graph[a][b] |= graph[a][k] & graph[k][b];
            }
        }
    }

    cin >> m;
    cin.ignore();
    while (m--) {
        string s;
        std::getline(std::cin, s);
        int a = s[0] - 'a', b = s.back() - 'a';
        cout << (graph[a][b] ? ('T') : ('F')) << '\n';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}