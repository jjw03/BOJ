#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, std::greater<int>> BFS(const vector<vector<int>>& g, int start, int K) {
	priority_queue<int, vector<int>, std::greater<int>> ret;

	vector<int> dist(g.size(), INT_MAX);
	dist[start] = 0;

	queue<int> to_visit;
	to_visit.push(start);

	while (!to_visit.empty()) {
		int cur = to_visit.front();
		to_visit.pop();

		if (dist[cur] == K) ret.push(cur);

		for (const int next : g[cur]) {
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				to_visit.push(next);
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> g(N);
	while (M--) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}

	auto ret = BFS(g, X - 1, K);
	if (ret.empty()) cout << -1;
	else {
		while (!ret.empty()) {
			cout << ret.top() + 1 << '\n';
			ret.pop();
		}
	}

	return 0;
}