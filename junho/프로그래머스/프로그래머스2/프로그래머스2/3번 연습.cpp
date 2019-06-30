#include <iostream>

using namespace std;

int main() {
	int N;
	int Dp[2][1010] = {};
	int A[1010] = {};
	int max = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		int max_A = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				if (max_A < Dp[0][j]) {
					max_A = Dp[0][j];
				}
			}
		
		}
		Dp[0][i] = max_A + 1;
	}

	for (int i = N; i >= 1; i--) {
		int max_A = 0;
		for (int j = N; j > i; j--) {
			if (A[i] > A[j]) {
				if (max_A < Dp[1][j]) {
					max_A = Dp[1][j];
				}
			}

		}
		Dp[1][i] = max_A + 1;
	}




}