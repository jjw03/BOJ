#include <bits/stdc++.h>
using namespace std;

/*
* 꼭 주석 읽기
* 문제를 단순 요약하자면 convex hull을 구하는 것은 동일하지만 예외 처리가 관건인 문제였음
*/

struct pos {
    long long x;
    long long y;
    pos(long long x = 0, long long y = 0) : x(x), y(y) {}
    bool operator<(const pos& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pos> points;
    points.reserve(N);

    int hull_cnt = 0;
    for (int i = 0; i < N; i++) {
        pos in; char is_hull;
        cin >> in.x >> in.y >> is_hull;

        if (is_hull == 'Y') {
            hull_cnt++;
            points.push_back(in);
        }
    }

    //1차 sort: x, y 기준 오름차순
    sort(points.begin(), points.end());

    //기준점(좌측 최하단) 정하기
    pos pivot = points.front();

    auto CCW = [](const pos& a, const pos& b, const pos& c) {
        long long cross = (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);
        return cross;
        };

    auto dist = [](const pos& a, const pos& b) {
        return (long long)(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
        };

    //반시계방향 정렬
    //1순위 기준: CCW를 유지하는 점이 우선적
    //2순위 기준(한직선 위에 있을 경우): 거리가 더 짧은 점이 우선
    sort(points.begin(), points.end(), [&](const pos& a, const pos& b) {
        long long cross = CCW(pivot, a, b);
        if (cross == 0) {
            return dist(pivot, a) < dist(pivot, b);
        }
        return cross > 0;
        });

    //정렬된 점들에 대해서 다시 convex hull 구하기(pop 과정에서 점을 버리지 않고 다시 넣음)
    vector<pos> convex_hull(N);
    convex_hull.reserve(N);

    convex_hull[0] = points[0];
    convex_hull[1] = points[1];

    /*
    * 나중에 보면 잊을 것 같아서 설명을 남김
    * convex hull을 다시 구하는 과정에서 현재 정렬된 기준으로 계산하면
    * 같은 직선상에 있는 점들을 올바른 순서로 구성하지 못함
    * 정확히는 첫번째로 만나는 직선은 처리가 가능하지만 두번째로 만나는 직선은 처리가 불가능
    * ex) (0, 0), (1, 1), (2, 2), (3, 3), (6, 2), (4, 0), (2, 0)
    * 
    * 위의 예시에서 (4,0), (2,0)은 처리가 가능하지만
    * (1,1),(2,2),..은 역순으로 처리됨
    * 
    * 그렇다고 두번째 직선을 처리하기 위한 스택이나 다른 자료구조를 추가적으로 선언하긴 귀찮아서
    * ccw_index를 만든것임. 이게 뭐냐?
    * 
    * 두번째 직선상에 있는 점들을 convex_hull 벡터의 뒤에 삽입하는 거임
    * push back 연산은 아니고 인덱스를 조작해서 역순으로 삽입함
    * 
    * 이렇게 계산하면 기존의 볼록 껍질 점들은 반시계 방향으로 만들어지면서
    * 두번째 직선의 점들은 N - 1 ~ ccw_index까지 역순으로 들어감
    * 
    * 주의할점은 두번째 직선에서 처음으로 처리된 점은 기존 점들의 마지막 부분에 붙어있음
    * 위의 예시에서는 (1,1)이 그에 해당됨 / (0,0)이 pivot
    * 
    * 그래서 코드 마지막 부분에 한 점만 따로 출력하는 것을 볼 수 있음
    */
    int pivot_a = 0, pivot_b = 1, ccw_index = N;
    for (int i = 2; i < points.size(); i++) {
        //CCW가 아닐 경우에는 벡터의 뒤쪽으로 삽입
        if (CCW(convex_hull[pivot_a], convex_hull[pivot_b], points[i]) < 0) {
            convex_hull[--ccw_index] = points[i];
        }
        //CCW를 이루므로 그대로 push
        else {
            convex_hull[i] = points[i];
            pivot_a++, pivot_b++;
        }
    }

    cout << hull_cnt << '\n';
    for (int i = 0; i < pivot_b; i++)
        cout << convex_hull[i].x << ' ' << convex_hull[i].y << '\n';
    
    for (int i = ccw_index; i < N; i++)
        cout << convex_hull[i].x << ' ' << convex_hull[i].y << '\n';

    cout << convex_hull[pivot_b].x << ' ' << convex_hull[pivot_b].y << '\n';

    return 0;
}
