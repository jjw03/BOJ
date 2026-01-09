#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/*
 * 간단한 구현문제
 * rotation되면 pop 방향이 바뀌므로 deque을 사용한다
 */

int Q;

class dq {
    private:
        int front_dir;  // 0: +x, 1: -y, 2: -x, 3: +y
        int cnt_ball;
        int cnt_wall;
        deque<int> q;   // 0: wall, 1: ball
        
        // 큐 방향에 따라 공 제거
        void apply_gravity(){
            if(front_dir == 0 || front_dir == 2) return;

            if(front_dir == 1){
                while(!q.empty() && q.front()){
                    q.pop_front();
                    --cnt_ball;
                }
            }
            else{
                while(!q.empty() && q.back()){
                    q.pop_back();
                    --cnt_ball;
                }
            }
        }

    public:
        dq() : front_dir(0), cnt_ball(0), cnt_wall(0), q(deque<int>()) {}

        void push_ball(){
            if(front_dir == 3) return;  // 큐의 앞쪽이 +y 방향
            if(front_dir == 1 && q.empty()) return; // 큐의 앞쪽이 -y 방향이고 가림막이 없음

            q.push_back(1);
            ++cnt_ball;
        }

        void push_wall(){
            q.push_back(0);
            ++cnt_wall;
        }

        void pop(){
            if(q.empty()) return;

            if(q.front()) --cnt_ball;
            else --cnt_wall;

            q.pop_front();

            apply_gravity();
        }

        void rotate_left(){
            front_dir = (4 + front_dir - 1) % 4;
            apply_gravity();
        }

        void rotate_right(){
            front_dir = (front_dir + 1) % 4;
            apply_gravity();
        }

        inline int count_ball(){
            return cnt_ball;
        }

        inline int count_wall(){
            return cnt_wall;
        }
};

void init(){
    cin >> Q;
}

void solve(){
    dq _dq;
    while(Q--){
        string query;
        cin >> query;
        
        if(query == "push"){
            char dir;
            cin >> dir;
            
            if(dir == 'b')
                _dq.push_ball();
            else
                _dq.push_wall();
        }
        else if(query == "pop"){
            _dq.pop();
        }
        else if(query == "rotate"){
            char dir;
            cin >> dir;

            if(dir == 'l')
                _dq.rotate_left();
            else
                _dq.rotate_right();
        }
        else{
            char type;
            cin >> type;

            if(type == 'b')
                cout << _dq.count_ball();
            else
                cout << _dq.count_wall();
            cout << '\n';
        }
    }
}

int main(){
    FAST_IO;

    init();
    solve();

    return 0;
}
