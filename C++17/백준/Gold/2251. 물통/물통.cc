#include <bits/stdc++.h>
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0)
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int A, B, C;
char possible[201];
char visited[201][201][201];

struct st {
    int a;
    int b;
    int c;
    st(int a, int b, int c) :
        a(a), b(b), c(c) { }
};

void bfs() {
    visited[0][0][C] = 1;

    queue<st> to_visit;
    to_visit.push({ 0, 0, C });

    while (!to_visit.empty()) {
        auto [a, b, c] = to_visit.front();
        to_visit.pop();

        if (a == 0)
            possible[c] = 1;

        int na, nb, nc;
        // a -> b, a -> c
        if (a > 0) {
            // a -> b
            na = max(0, a + b - B), nb = min(B, a + b), nc = c;
            if (!visited[na][nb][nc]) {
                to_visit.push(st(na, nb, nc));
                visited[na][nb][nc] = 1;
            }

            // a -> c
            na = max(0, a + c - C), nb = b, nc = min(C, a + c);
            if (!visited[na][nb][nc]) {
                to_visit.push(st(na, nb, nc));
                visited[na][nb][nc] = 1;
            }
        }

        // b -> a, b -> c
        if (b > 0) {
            // b -> a
            na = min(A, b + a), nb = max(0, b + a - A), nc = c;
            if (!visited[na][nb][nc]) {
                to_visit.push(st(na, nb, nc));
                visited[na][nb][nc] = 1;
            }

            // b -> c
            na = a, nb = max(0, b + c - C), nc = min(C, b + c);
            if (!visited[na][nb][nc]) {
                to_visit.push(st(na, nb, nc));
                visited[na][nb][nc] = 1;
            }
        }

        // c -> a, c -> b
        if (c > 0) {
            // c -> a
            na = min(A, c + a), nb = b, nc = max(0, c + a - A);
            if (!visited[na][nb][nc]) {
                to_visit.push(st(na, nb, nc));
                visited[na][nb][nc] = 1;
            }

            // c -> b
            na = a, nb = min(B, c + b), nc = max(0, c + b - B);
            if (!visited[na][nb][nc]) {
                to_visit.push(st(na, nb, nc));
                visited[na][nb][nc] = 1;
            }
        }
    }
}

void init() {
    cin >> A >> B >> C;
}

void solve() {
    bfs();
    for (int amount = 0; amount <= C; ++amount) {
        if (possible[amount])
            cout << amount << ' ';
    }
}

int main() {
    FAST_IO;

    init();
    solve();

    return 0;
}
