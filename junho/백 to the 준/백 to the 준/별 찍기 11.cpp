#include<iostream>
#include<stdio.h>

char arr[3072][6144];
using namespace std;
void star(int n, int x, int y) {

	if (n == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + +1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x + 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x] = '*';
		return;

	}

	star(n / 2, x, y);
	star(n / 2, x - (n / 2), y + (n / 2));
	star(n / 2, x + (n / 2), y + (n / 2));


}

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			arr[i][j] = ' ';

		}
	}


	star(n, n - 1, 0);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			printf("%c", arr[i][j]);

		}
		printf("\n");
	}


}

