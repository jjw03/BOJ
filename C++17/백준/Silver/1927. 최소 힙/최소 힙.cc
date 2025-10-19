#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> heap;
	heap.reserve(1e5);
	while (n--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (heap.empty()) cout << 0;
			else {
				pop_heap(heap.begin(), heap.end(), std::greater<int>());
				cout << heap.back();
				heap.pop_back();
			}
			cout << '\n';
		}
		else {
			heap.push_back(a);
			push_heap(heap.begin(), heap.end(), std::greater<int>());
		}
	}

	return 0;
}