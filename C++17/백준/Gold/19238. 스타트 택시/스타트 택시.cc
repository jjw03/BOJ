#include <bits/stdc++.h>
using namespace std;

int N, M, fuel;

vector<vector<int>> g; // -1: wall, 1~ : passenger
vector<pair<int, int>> towards;

vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

struct dist_fuel {
    int x;
    int y;
    int fuel;
    dist_fuel(pair<int, int> p, int fuel) : x(p.first), y(p.second), fuel(fuel) {}
};

void move(const pair<int, int>& start, const pair<int, int>& end) {
    vector<vector<pair<int, int>>> dist(N, vector<pair<int, int>>(N, { INT_MAX, INT_MAX }));
    dist[start.first][start.second] = { 0, fuel };

    queue<dist_fuel> to_visit;
    to_visit.push({ start, fuel });

    while (!to_visit.empty()) {
        auto [curx, cury, curf] = to_visit.front();
        to_visit.pop();

        if (curf == 0) continue;

        for (const auto& [dx, dy] : dir) {
            int nx = curx + dx, ny = cury + dy;
            if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
            if (g[nx][ny] == -1) continue;

            int ndist = dist[curx][cury].first + 1;
            if (dist[nx][ny].first > ndist) {
                dist[nx][ny] = { ndist, curf - 1 };
                to_visit.push({ {nx, ny}, curf - 1 });
            }
        }
    }

    if (dist[end.first][end.second].first == INT_MAX)
        fuel = -1;
    else
        fuel = dist[end.first][end.second].first * 2 + dist[end.first][end.second].second;
}

pair<int, int> find_nearest(const pair<int, int>& taxi) {
    int min_dist = INT_MAX;
    pair<int, int> ret = { -1, -1 };

    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    dist[taxi.first][taxi.second] = 0;

    queue<dist_fuel> to_visit;
    to_visit.push({ taxi, fuel });

    while (!to_visit.empty()) {
        auto [curx, cury, curf] = to_visit.front();
        to_visit.pop();

        if (g[curx][cury] > 0 && min_dist >= dist[curx][cury]) {
            if (min_dist == dist[curx][cury]) {
                if (curx != ret.first) {
                    ret = (ret.first < curx ? ret : make_pair(curx, cury));
                }
                else {
                    ret = (ret.second < cury ? ret : make_pair(curx, cury));
                }
            }
            else {
                min_dist = dist[curx][cury];
                ret = { curx, cury };
            }
        }

        if (curf == 0) continue;

        for (const auto& [dx, dy] : dir) {
            int nx = curx + dx, ny = cury + dy;
            if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
            if (g[nx][ny] == -1) continue;

            int ndist = dist[curx][cury] + 1;
            if (dist[nx][ny] > ndist) {
                dist[nx][ny] = ndist;
                to_visit.push({ {nx, ny}, curf - 1 });
            }
        }
    }

    if (ret.first == -1)
        fuel = -1;
    else
        fuel -= dist[ret.first][ret.second];

    return ret;
}

void taxi(const pair<int, int> start) {
    pair<int, int> tpos = start;
    while (M--) {
        pair<int, int> ns = find_nearest(tpos);
        if (fuel == -1) break;

        pair<int, int> ne = towards[g[ns.first][ns.second] - 1];
        g[ns.first][ns.second] = 0;

        move(ns, ne);

        if (fuel == -1) break;
        tpos = ne;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> fuel;

    g.resize(N, vector<int>(N));
    towards.reserve(M);

    for (vector<int>& v : g) {
        for (int& i : v) {
            cin >> i;
            if (i == 1) i = -1;
        }
    }

    int tx, ty;
    cin >> tx >> ty;
    
    int toward_idx = 1;
    for (int i = 0; i < M; i++) {
        int px, py, hx, hy;
        cin >> px >> py
            >> hx >> hy;
        g[px - 1][py - 1] = toward_idx++;
        towards.push_back({ hx - 1, hy - 1 });
    }

    taxi({ tx - 1, ty - 1 });
    cout << fuel;

    return 0;
}