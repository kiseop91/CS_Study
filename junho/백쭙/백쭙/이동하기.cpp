#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int mir[MAX + 1][MAX + 1];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mir[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			mir[i][j] = max(max(mir[i - 1][j - 1], mir[i - 1][j]), mir[i][j - 1]) + mir[i][j];
		}
	}

	cout << mir[N][M];


}