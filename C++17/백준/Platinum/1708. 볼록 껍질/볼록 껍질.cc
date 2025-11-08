#include <bits/stdc++.h>
using namespace std;

/*
* Graham Scan
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    struct pos {
        long long x;
        long long y;
        pos(long long x = 0, long long y = 0) : x(x), y(y) {}
        bool operator<(const pos& other) const {
            if (x != other.x) return x < other.x;
            return y < other.y;
        }
    };

    //1차 sort: x, y 기준 오름차순
    vector<pos> vec;
    for (int i = 0; i < N; i++) {
        pos in;
        cin >> in.x >> in.y;
        vec.push_back(in);
    }
    sort(vec.begin(), vec.end());

    //기준점(좌측 최하단) 정하기
    vector<pos> points;
    points.reserve(N);
    points.push_back(vec.front());

    auto CCW = [](const pos& a, const pos& b, const pos& c) {
        long long cross = (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);
        return cross;
        };

    auto dist = [](const pos& a, const pos& b) {
        return (long long)(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
        };

    //2차 sort: 반시계방향 sorting
    sort(vec.begin(), vec.end(), [&](const pos& a, const pos& b) {
        //기준: CCW를 유지하는 점이 우선
        long long cross = CCW(points.front(), a, b);
        //세 점이 직선 위에 있을 경우 기준점과 거리가 짧은 점이 우선
        if (cross == 0) {
            return dist(points.front(), a) < dist(points.front(), b);
        }
        return cross > 0;
        });

    points.push_back(vec[1]);

    //Graham Scan
    for (int i = 2; i < vec.size(); i++) {
        while (points.size() > 1 && CCW(points[points.size() - 2], points[points.size() - 1], vec[i]) <= 0) {
            points.pop_back();
        }
        points.push_back(vec[i]);
    }

    cout << points.size();

    return 0;
}
