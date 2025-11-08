#include <bits/stdc++.h>
using namespace std;

/*
* CCW 안쓰고 행렬 연산으로 구함
* 두 선분의 방정식을 parametric equation으로 나타내고
* 두 방정식의 연립해를 구하면(교차하도록 만드는 각 방정식의 t값을 구하면)
* 교차 여부 판정 가능
* 
* 두 t값중 하나라도 0 ~ 1의 범위를 벗어난다면 두 선분은 교차하지 않음
*/

struct pos {
    double x;
    double y;
    pos(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    pos p1, p2, p3, p4;
    cin >> p1.x >> p1.y
        >> p2.x >> p2.y
        >> p3.x >> p3.y
        >> p4.x >> p4.y;

    // | a1 b1 | | x |  =  | k1 |
    // | a2 b2 | | y |     | k2 |
    auto linear_solution = [](const pos a, const pos b, const pos k, pos& solution) {
        //inverse matrix
        double determinant = a.x * b.y - b.x * a.y;

        //det == 0 -> parallel line
        if (fabs(determinant) < numeric_limits<double>::epsilon())
            return false;

        /*
        * x      1  |  b2  -b1 | | k1 |
        *    =  --- |          | |    |
        * y     det | -a2   a1 | | k2 |
        */
        solution.x = (k.x * b.y - k.y * b.x) / determinant;
        solution.y = (-k.x * a.y + k.y * a.x) / determinant;

        return true;
        };

    //선분 위에 점이 있는지 확인
    auto is_above_line = [](const pair<pos, pos> line, const pos point) {
        pos p1 = line.first, p2 = line.second;

        //두 벡터 point - line_1 / line_2 - line_1의 외적
        double cross_product = (point.x - p1.x) * (p2.y - p1.y) - (point.y - p1.y) * (p2.x - p1.x);
        
        if (fabs(cross_product) <numeric_limits<double>::epsilon()) {
            return (min(p1.x, p2.x) <= point.x && point.x <= max(p1.x, p2.x)) &&
                (min(p1.y, p2.y) <= point.y && point.y <= max(p1.y, p2.y));
        }
        else {
            return false;
        }
        };

    //두 선분이 겹치거나 한 점이 다른 선분위에 위치할 경우
    if ((is_above_line({ p1, p2 }, p3) || is_above_line({ p1, p2 }, p4))
        || ( is_above_line({ p3, p4 }, p1) || is_above_line({ p3, p4 }, p2))) {
        cout << 1;
    }
    //그 외에는 교차 판정(행렬 연산)
    else {
        pos ans;
        bool is_crossing = 
            linear_solution(
            { p2.x - p1.x,p2.y - p1.y }, 
            { p3.x - p4.x,p3.y - p4.y }, 
            { p3.x - p1.x,p3.y - p1.y }, ans);

        if (!is_crossing || ((ans.x < 0.0 || 1.0 < ans.x) || (ans.y < 0.0 || 1.0 < ans.y))) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }

    return 0;
}
