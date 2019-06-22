#include <iostream>

using namespace std;


int arr[3];// arr[0] = -1의 개수, [1] = 0의 개수, [2] = 1 의 개수
int board[3000][3000];

bool check_board(int a,int b,int c) {

	if (c == 1) {
		return true;
	}
	
	int cmp = board[a][b];
	bool chk = true;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if (cmp == board[a + i][b + j]) { continue; }
			chk = false;
		}
	}
	return chk;
}

void recursion(int a, int b, int c) {

	if(check_board(a,b,c)){

		if (board[a][b] == -1) { arr[0]++; }
		else if (board[a][b] == 0) { arr[1]++; }
		else { arr[2]++; }
	}
	else {

		for(int i=a;i<a+c; i=i+c/3){
			for (int j = b; j < b+c; j = j + c / 3) {
				recursion(i, j, c / 3);
			}
		}

	}
	
}



int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	recursion(0, 0, N);
	
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << endl;
	}


}