#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const int MAX = 2000;

int su[MAX + 1];
bool cache[MAX + 1][MAX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; //수열의 크기
	

	for (int i = 0; i < n; i++) {
		cin >> su[i];
//		scanf_s("%d", &su[i]);
	}
	
	for (int i = 0; i < n; i++) {
		cache[i][i] = true;
	}
	for (int i = 0; i < n; i++) {
		if (su[i] == su[i + 1]) { cache[i][i + 1] = true; }
	}
	
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (su[j] == su[j + i] && cache[j + 1][j + i - 1])
			{
				cache[j][j + i] = true;
			}
		}
	}

	int m;
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (cache[a-1][b-1]) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}