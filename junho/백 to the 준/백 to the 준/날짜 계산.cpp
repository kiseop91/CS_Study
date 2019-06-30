#include <iostream>

using namespace std;

int E, S, M;

int main() {
	cin >> E >> S >> M;
	int a = 0, b = 0, c = 0;
	int cnt = 0;
	while (1) {
		if (a == E && b == S && c == M) { break; }
		cnt++;
		a++;
		b++;
		c++;

		if (a > 15) {
			a %= 15;
		}
		if (b > 28) {
			b %= 28;
		}
		if (c > 19) {
			c %= 19;
		}

	}
	cout << cnt;

}