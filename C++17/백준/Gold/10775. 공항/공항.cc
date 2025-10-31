#include <bits/stdc++.h>
using namespace std;

/*
* 각 비행기가 도킹 가능한 위치는 1 ~ g_i이므로
* 많은 비행기가 중첩되는 값이 낮은 게이트들은 최대한 피해서 배치하는 것이 좋다
* 따라서 그리디하게 현재 비행기가 위치할 수 있는 게이트들 중
* 가장 숫자가 큰 게이트에 위치시키는 것이 최대로 도킹시킬 수 있는 방법이다
* 
* 추가적으로 게이트 수가 최대 10^5이므로 도킹 위치를 나이브하게 찾으면 시간초과 날게 뻔하다
* 유니온 파인드로 점유된 게이트들의 집합을 관리한다
* 각 집합의 루트 노드는 항상 그 자식 노드보다 작은 값을 가지며 도킹 가능한 위치이다
* 자식 노드는 모두 점유된 게이트이다
*/

vector<int> parent;

int find_root(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
    int root_x = find_root(x), root_y = find_root(y);
    //더 작은 값으로 루트 설정
    if (root_x < root_y) parent[root_y] = root_x;
    else parent[root_x] = root_y;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int G, p;
    cin >> G >> p;

    parent.resize(G + 1);
    for (int i = 0; i <= G; i++) parent[i] = i;

    vector<int> gate(p);
    for (int& i : gate) cin >> i;

    int ans = 0;
    for (const int& dock : gate) {
        int dock_point = find_root(dock);
        if (dock_point == 0) break;    //도킹이 불가능할 경우
        ans++;
        union_root(dock_point, dock_point - 1);    //도킹 후 바로 앞 게이트와 유니온
    }

    cout << ans;

    return 0;
}
