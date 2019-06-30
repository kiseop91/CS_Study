#include <iostream>


using namespace std;
int dp[15];

int find_dp(int a) {
	if (a == 0) return 0;
	if (a == 1) return 1;
	if (a == 2) return 2;
	if (a == 3) return 4;
	
	return find_dp(a - 1) + find_dp(a - 2) + find_dp(a - 3);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		cout << find_dp(c)<<"\n";
	}
}