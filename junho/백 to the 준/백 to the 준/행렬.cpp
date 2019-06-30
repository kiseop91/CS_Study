#include <iostream>
#include <string>

using namespace std;

int main() {
	int N=0, M=0;
	string s_1[50];
	string s_2[50];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s_1[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> s_2[i];
	}
	int res = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (s_1[i][j] != s_2[i][j]) {
				res += 1;
				for (int k = i; k < i+3; k++) {
					for (int z = j; z < j + 3; z++) {
						if (s_1[k][z] == '0') { s_1[k][z] = '1'; }
						else { s_1[k][z] = '0'; }
					}
				}

			}

		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s_1[i][j] != s_2[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << res;
	return 0;



}