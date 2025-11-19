#include <bits/stdc++.h>
using namespace std;

int A, B, N;

vector<int> dir;
vector<char> graph, degree;

void make_graph() {
	dir = { -A, -B, A, B };
	graph.resize(N + 1, 0);	// 0b0000 bit-masking
	degree.resize(N + 1, 0);

	queue<int> to_visit;
	to_visit.push(1);

	while(!to_visit.empty()) {
		int cur = to_visit.front();
		to_visit.pop();

		if (graph[cur] == 0b1111) continue;

		for (int i = 0; i < 4; i++) {
			int next = cur + dir[i];
			if (next < 1 || N < next) continue;
			if ((graph[cur] >> i) & 1) continue;

			graph[cur] |= (1 << i);
			graph[next] |= (1 << ((i + 2) % 4));

			degree[cur]++, degree[next]++;

			to_visit.push(next);
		}
	}
}

// impossible condition
// 1. existence of degree == 0
// 2. odd degree nodes > 2
bool check_possiblity(int& start, int& end) {
	vector<int> candid;
	int visited = 0;

	for (int n = 1; n <= N; n++) {
		if (degree[n] == 0) continue;
		
		visited++;
		if (degree[n] % 2 == 1) candid.push_back(n);
	}

	if (candid.empty()) {
		start = end = 1;
	}
	else if (candid.size() == 2) {
		start = candid[0];
		end = candid[1];
	}
	else return false;

	return visited == N;
}

void DFS(vector<int>& path, int cur) {
	for (int i = 0; i < 4; i++) {
		if (((graph[cur] >> i) & 1) == 0) continue;

		int next = cur + dir[i];

		graph[cur] ^= (1 << i);
		graph[next] ^= (1 << ((i + 2) % 4));

		DFS(path, next);
	}

	path.push_back(cur);
}

vector<int> euler_DFS(int start) {
	vector<int> ret;

	DFS(ret, start);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B >> N;

	if (N == 1) {
		cout << 1 << '\n' << 1;
	}
	else if (A == B) {
		if (A == 1) {
			cout << N << '\n';
			for (int i = 1; i <= N; i++) cout << i << ' ';
		}
		else {
			cout << -1;
		}
	}
	else {
		make_graph();

		int s = 0, e = 0;
		if (!check_possiblity(s, e)) {
			cout << -1;
		}
		else {
			vector<int> ret = euler_DFS(s);

			cout << ret.size() << '\n';
			for (auto riter = ret.rbegin(); riter != ret.rend(); riter++)
				cout << *riter << ' ';
		}
	}

	return 0;
}