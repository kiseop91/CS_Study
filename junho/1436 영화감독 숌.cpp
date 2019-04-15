#include <stdio.h>

int arr[10]; // arr[0]이 일의자리 수, arr[1]이 십의자리 수 ...

void up(int n) {

	if (arr[n] == 9) {

		arr[n] = 0;

		up(n + 1);

	}

	else arr[n]++;

}

int main() {

	int N;

	scanf("%d", &N);

	arr[0] = 6;

	arr[1] = 6;

	arr[2] = 6;

	while (1) {

		for (int i = 2; i < 10; ++i) {

			if (arr[i - 2] == 6 && arr[i - 1] == 6 && arr[i] == 6) {

				N--;

				break;

			}

		}

		if (N == 0) {

			int good = 0;

			for (int i = 9; i >= 0; --i) {

				if (!good) {

					if (arr[i] == 0) continue;

					else {

						good = 1;

						printf("%d", arr[i]);

					}

				}

				else printf("%d", arr[i]);

			}

			break;

		}

		else up(0);

	}

}
