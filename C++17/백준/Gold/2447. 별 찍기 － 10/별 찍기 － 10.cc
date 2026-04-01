#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <functional>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;

void MakePattern(int N, int pivotX, int pivotY, vector<string>& vec) {

	int subPattern;
	subPattern = N / 3;

	if (subPattern == 1) {
		vec[pivotX - 1][pivotY - 1] = '*';
		vec[pivotX][pivotY - 1] = '*';
		vec[pivotX + 1][pivotY - 1] = '*';
		vec[pivotX - 1][pivotY] = '*';
		vec[pivotX + 1][pivotY] = '*';
		vec[pivotX - 1][pivotY + 1] = '*';
		vec[pivotX][pivotY + 1] = '*';
		vec[pivotX + 1][pivotY + 1] = '*';
	}
	else
	{
		MakePattern(N / 3, pivotX - subPattern, pivotY - subPattern, vec);
		MakePattern(N / 3, pivotX, pivotY - subPattern, vec);
		MakePattern(N / 3, pivotX + subPattern, pivotY - subPattern, vec);
		MakePattern(N / 3, pivotX - subPattern, pivotY, vec);
		MakePattern(N / 3, pivotX + subPattern, pivotY, vec);
		MakePattern(N / 3, pivotX - subPattern, pivotY + subPattern, vec);
		MakePattern(N / 3, pivotX, pivotY + subPattern, vec);
		MakePattern(N / 3, pivotX + subPattern, pivotY + subPattern, vec);
	}


}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<string> AnsVec;
	string str(N, ' ');

	for (int i = 0; i < N; i++) AnsVec.push_back(str);

	MakePattern(N, (N + 1) / 2 - 1, (N + 1) / 2 - 1, AnsVec);

	for (string& i : AnsVec) cout << i << '\n';

	return 0;
}