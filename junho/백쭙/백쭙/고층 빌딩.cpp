#include <iostream>
using namespace std;

const int MOD = 1000000007;
int cache[101][101][101];

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	long long temp;
	cache[1][1][1] = 1;
	cache[2][2][1] = 1;
	cache[2][1][2] = 1;

	for (int i = 3; i <= n; i++) {
		cache[i][i][1] = cache[i][1][i] = 1;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				temp = cache[i - 1][j][k];
				temp = (temp*(i - 2)) % MOD;
				temp = (temp + cache[i - 1][j - 1][k]) % MOD;
				temp = (temp + cache[i - 1][j][k - 1]) % MOD;

				cache[i][j][k] = temp;
			}
		}
	}
	cout << cache[n][l][r];

}