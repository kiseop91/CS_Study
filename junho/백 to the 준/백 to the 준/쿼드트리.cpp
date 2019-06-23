#include<stdio.h>
#include<iostream>
#include<array>
#include<vector>

using namespace std;
int arr[64][64];
vector<char>v;
int cnt = 0;

void zip(int n, int x, int y) {
	int sum = 0;
	for (int i = x; i < x + n; i++) {

		for (int j = y; j < y + n; j++) {
			sum += arr[i][j];

			//		cout << i << "," << j<<","<<sum<< endl;

		}

	}

	if (sum == n * n) {
		v.push_back('1');
		//		cout << "1»ðÀÔ"<<endl;
		return;
	}
	if (sum == 0) {
		v.push_back('0');
		//		cout << "0»ðÀÔ" << endl;
		return;
	}
	v.push_back('(');
	zip(n / 2, x, y);
	zip(n / 2, x, y + n / 2);

	zip(n / 2, x + n / 2, y);
	zip(n / 2, x + n / 2, y + n / 2);
	v.push_back(')');
}


int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	zip(n, 0, 0);
	for (int i = 0; i < v.size(); i++) {
		printf("%c", v[i]);
	}

}