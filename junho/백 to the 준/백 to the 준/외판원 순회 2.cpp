#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int N;
int arr[12][12];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = INT_MAX;
	vector<int> v;
	int cmp = 0;
	for (int i = 0; i < N; i++) {
		v.push_back(i);
	}

	do {
		bool flag = true;
		int cmp = 0;
		for (int i = 0; i < N - 1; i++) {
			if (!arr[v[i]][v[i + 1]]) { flag = false; break; }
			else {
				cmp += arr[v[i]][v[i + 1]];
			}
		}
		if (flag) {
			if (arr[v[N - 1]][v[0]] != 0) {

				cmp += arr[v[N - 1]][v[0]];
				ans = min(ans, cmp);
			}
		}
	} while (next_permutation(v.begin()+1, v.end()));
	cout << ans;

}