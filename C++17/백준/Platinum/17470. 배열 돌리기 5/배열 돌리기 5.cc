#include <bits/stdc++.h>
using namespace std;

int N, M, R;
struct face_info {
	int left_side;
	int up_side;
};

void compute_query(face_info& arr_face, deque<int>& order) {
	int q;
	for (int i = 0; i < R; i++) {
		cin >> q;
		if (q == 1) {
			std::swap(order[0], order[3]);
			std::swap(order[1], order[2]);
			arr_face.up_side = (arr_face.up_side + 2) % 4;
		}
		else if (q == 2) {
			std::swap(order[0], order[1]);
			std::swap(order[2], order[3]);
			arr_face.left_side = (arr_face.left_side + 2) % 4;
		}
		else if (q == 3) {
			order.push_front(order.back());
			order.pop_back();
			int temp = arr_face.left_side;
			arr_face.left_side = (arr_face.up_side + 2) % 4;
			arr_face.up_side = temp;
		}
		else if (q == 4) {
			order.push_back(order.front());
			order.pop_front();
			int temp = arr_face.up_side;
			arr_face.up_side = (arr_face.left_side + 2) % 4;
			arr_face.left_side = temp;
		}
		else if (q == 5) {
			order.push_front(order.back());
			order.pop_back();
		}
		else
		{
			order.push_back(order.front());
			order.pop_front();
		}
	}
}

void print_result(const vector<vector<vector<int>>>& arr, const vector<int>& order,
	const face_info& arr_face) {

	const bool is_tilted = (arr_face.left_side % 2 != 0);

	const int new_row = (is_tilted) ? M / 2 : N / 2;
	const int new_col = (is_tilted) ? N / 2 : M / 2;

	const vector<pair<int, int>> pos_weight = {
		{0, 0}, {0, new_col}, {new_row, 0}, {new_row, new_col}
	};
	const vector<vector<pair<int, int>>> dir = {	//first: row operation, second: col operation
		{{1, 1},  {1, -1}},
		{{-1, 1}, {-1, -1}}
	};
	
	vector<vector<int>> ans(new_row * 2, vector<int>(new_col * 2));

	if (is_tilted) {
		pair<int, int> dir_idx;
		dir_idx.first = (arr_face.left_side != 1);
		dir_idx.second = (arr_face.up_side != 0);

		int row_weight = dir[dir_idx.first][dir_idx.second].first;
		int col_weight = dir[dir_idx.first][dir_idx.second].second;

		for (int i = 0; i < order.size(); i++) {
			const int cur_order = order[i];

			int arr_col = (arr_face.up_side != 0) ? new_row - 1 : 0;
			for (int j = 0; j < new_row; j++) {

				int arr_row = (arr_face.left_side != 1) ? new_col - 1 : 0;
				for (int k = 0; k < new_col; k++) {

					ans[pos_weight[i].first + j][pos_weight[i].second + k]
						= arr[cur_order][arr_row][arr_col];

					arr_row += row_weight;
				}
				arr_col += col_weight;
			}
		}
	}
	else
	{
		pair<int, int> dir_idx;
		dir_idx.first = (arr_face.up_side != 1);
		dir_idx.second = (arr_face.left_side != 0);

		int row_weight = dir[dir_idx.first][dir_idx.second].first;
		int col_weight = dir[dir_idx.first][dir_idx.second].second;

		for (int i = 0; i < order.size(); i++) {
			const int cur_order = order[i];

			int arr_row = (arr_face.up_side != 1) ? new_row - 1 : 0;
			for (int j = 0; j < new_row; j++) {

				int arr_col = (arr_face.left_side != 0) ? new_col - 1 : 0;
				for (int k = 0; k < new_col; k++) {

					ans[pos_weight[i].first + j][pos_weight[i].second + k]
						= arr[cur_order][arr_row][arr_col];

					arr_col += col_weight;
				}
				arr_row += row_weight;
			}
		}
	}

	for (const auto& vec : ans) {
		for (const int& i : vec) cout << i << ' ';
		cout << '\n';
	}
}

int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> N >> M >> R;
	
	//배열 입력
	vector<vector<vector<int>>> arr(4, vector<vector<int>>(N / 2, vector<int>(M / 2)));
	for (int i = 0; i < N / 2; i++) {
		for (int k = 0; k < M / 2; k++)
			cin >> arr[0][i][k];
		for (int k = 0; k < M / 2; k++)
			cin >> arr[1][i][k];
	}
	for (int i = 0; i < N / 2; i++) {
		for (int k = 0; k < M / 2; k++)
			cin >> arr[3][i][k];
		for (int k = 0; k < M / 2; k++)
			cin >> arr[2][i][k];
	}

	//연산 입력
	face_info arr_face = { 0, 1 };
	deque<int> order = { 0, 1, 2, 3 };
	compute_query(arr_face, order);

	//결과 배열 생성
	const vector<int> print_order = { order[0], order[1], order[3], order[2] };
	print_result(arr, print_order, arr_face);

	return 0;
}