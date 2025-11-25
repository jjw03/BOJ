#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * Q가 최대 20이므로 각 쿼리에 대해서 그래프 탐색을 반복해도 TLE에서 안전함
 */

int N, M;
vector<int> level;
vector<vector<int>> graph;
map<string, int> idx;

void init(){
    cin >> N >> M;

    level.resize(N, 0);
    graph.resize(N);

    int i = 0;
    while(M--){
        string a, b;
        cin >> a >> b;
        if(idx.find(a) == idx.end())
            idx.insert({a, i++});
        if(idx.find(b) == idx.end())
            idx.insert({b, i++});
        graph[idx[a]].push_back(idx[b]);
    }
}

int BFS(const int a, const int b){
    int ret = 0;
    vector<char> visited(N, 0);
    queue<int> to_visit;
    to_visit.push(a);
    to_visit.push(b);
    visited[a] = 1;
    visited[b] = 2;

    while(!to_visit.empty()){
        int cur = to_visit.front();
        to_visit.pop();

        for(int next : graph[cur]){
            if(visited[next] != 0){
                //BFS 도중 다르게 마킹된 노드를 만났을 경우 다음의 두가지 경우 뿐임
                //1. 다음 노드가 현재 a 또는 b
                //2. 다음 노드가 a와 b의 자식 노드
                //1의 경우 나이 순서를 알 수 있지만 2의 경우 불가능
                if(visited[next] != visited[cur] && (next == a || next == b))
                    ret = visited[cur];
                continue;
            }

            visited[next] = visited[cur];
            to_visit.push(next);
        }
    }

    return ret;
}

int main(){
    FAST_IO;

    init();

    int Q;
    cin >> Q;
    while(Q--){
        string a, b;
        cin >> a >> b;

        map<string, int>::iterator iter_a = idx.find(a), iter_b = idx.find(b);
        if(iter_a == idx.end() || iter_b == idx.end())
            cout << "gg";
        else{
            int ret = BFS((*iter_a).second, (*iter_b).second);
            if(ret == 0)
                cout << "gg";
            else if(ret == 1)
                cout << a;
            else
                cout << b;
        }
        cout << ' ';
    }

    return 0;
}
