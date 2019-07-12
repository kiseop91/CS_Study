#include <iostream>
#include <algorithm>

using namespace std;

const int max_int = 1000 + 1;

int d[max_int][32];
int a[max_int];
int t, w;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> w;
	
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= t; i++) {
		for (int j = w; j >= 0; j--) {
			
			if (a[i] % 2 == 1) {
				if (j % 2 == 0) {
					d[i][j] = max(d[i - 1][j], d[i - 1][j + 1]) + 1;
				}
				else {
					d[i][j] = max(d[i - 1][j], d[i - 1][j + 1]);
				}
			}
			else {
				if (j % 2 == 0) {
					d[i][j] = max(d[i - 1][j], d[i - 1][j + 1]);
				}
				else {
					d[i][j] = max(d[i - 1][j], d[i - 1][j + 1]) + 1;
				}
			}

		}
	}

	int res = 0;
	for (int j = 0; j <= w; j++) {
		res = max(res, d[t][j]);
	}
	cout << res;

}