#include <bits/stdc++.h>
using namespace std;

/*
* 색칠되지 않은 '면적'만 알면 됨
* 따라서 접힌 상태에서 역추적하여 색칠된 영역이 몇개인지 알아내면 정답을 구할 수 있음
* 
* 문제 예시에서 나온 예제로 생각해보면
* 마지막에 색칠한 영역은 2칸이고,
* 해당 단계 이전으로 돌아가면(다시 펼치면) 2 * 3으로 증가
* 다시 그 이전 단계로 돌아가면 2 * 3 + 3으로 증가
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long w, h, f, c, x1, y1, x2, y2;
    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

    //모든 단계를 거친후 w, h
    long long folded_w = max(w - f, f);
    long long folded_h = h / (c + 1);

    //색칠된 영역 역추적 1단계 (c + 1개의 영역)
    long long area = (x2 - x1) * (y2 - y1);
    long long colored_area = (c + 1) * area;

    //영역 역추적 2단계 (x = f 접기)
    long long folded_x = min(w - f, f);
    colored_area += (c + 1) * (x2 <= folded_x ? area : (x1 <= folded_x ? (folded_x - x1) * (y2 - y1) : 0));

    cout << w * h - colored_area;

    return 0;
}
