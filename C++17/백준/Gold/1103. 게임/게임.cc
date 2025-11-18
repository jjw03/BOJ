#include <bits/stdc++.h>
using namespace std;

/*
* 브루트포스로 모든 경우를 다하고 있으면 시간초과가 발생할게 뻔하기 때문에
* 각 칸에서 4가지 방향에 따른 최대 이동값을 저장하여 dp로 해결한다
*/

int N, M;
vector<pair<int, int>> dir = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

// -1: inf, 1~: finite
int board[51][51];
int memo[51][51];
int visited_stk[51][51];

int dp(int x, int y) {
	if (x < 0 || N <= x || y < 0 || M <= y) return 1;
	if (board[x][y] == -1) return 1;

	if (visited_stk[x][y] == 1) {
		return memo[x][y] = -1;
	}
	if (memo[x][y] != 0) return memo[x][y];

	visited_stk[x][y] = 1;

	int ret = 0, weight = board[x][y];
	for (const auto& [dx, dy] : dir) {
		int nx = x + dx * weight, ny = y + dy * weight;

		int r = dp(nx, ny);

		if (r == -1) {
			ret = -1;
			break;
		}

		ret = max(ret, r);
	}

	visited_stk[x][y] = 0;

	return memo[x][y] = (ret == -1 ? ret : ret + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int x = 0; x < N; x++) {
		string s; cin >> s;
		for (int y = 0; y < M; y++) {
			if (s[y] == 'H') board[x][y] = -1;
			else board[x][y] = s[y] - '0';
		}
	}

	int ans = dp(0, 0);
	cout << (ans == -1 ? ans : ans - 1);

	return 0;
}