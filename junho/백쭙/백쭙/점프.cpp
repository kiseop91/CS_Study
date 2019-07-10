#include <iostream> 
using namespace std;

const int MAX = 100;

long long board[MAX + 1][MAX + 1];
long long cnt[MAX + 1][MAX + 1];

int main() {
	long long N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	
	cnt[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) { continue; }
				int cmp = board[i][j];
				if (i + cmp < N) {
					cnt[i + cmp][j] += cnt[i][j];
				}
				if (j + cmp < N) {
					cnt[i][j + cmp] += cnt[i][j];

			}
		}
	}

	cout << cnt[N - 1][N - 1]<<'\n';

}