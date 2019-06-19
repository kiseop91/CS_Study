#include<stdio.h>
#include<iostream>
#include<array>
#include<vector>
#include<utility>
#include<algorithm>
#include<functional>
#include<string>

using namespace std;

int R, C, T;
int board[52][52];
int check[52][52];
int operation[52][52];
vector<int>v;

int dir_x[4] = { 0,-1,0,1 };
int dir_y[4] = { 1,0,-1,0 };

void setboard() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) { v.push_back(i); }
		}
	}
}

void board_print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}


}


void check_board() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < 4; k++) {
				int nr = i + dir_x[k];
				int nc = j + dir_y[k];
				if (nr<1 or nr>R) { check[i][j] -= 1; continue; }
				if (nc<1 or nc>C) { check[i][j] -= 1; continue; }
				if (nr == v[0] && nc == 1) { check[i][j] -= 1; continue; }
				if (nr == v[1] && nc == 1) { check[i][j] -= 1; continue; }

			}
		}
	}
	check[v[0]][1] = 0;
	check[v[1]][1] = 0;
}

void check_board_print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
}

void set_operation_board() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int temp = (board[i][j] / 5);
			if (temp == 0) { continue; }
			for (int k = 0; k < 4; k++) {
				int nr = i + dir_x[k];
				int nc = j + dir_y[k];
				if (nr<1 or nr>R) { continue; }
				if (nc<1 or nc>C) { continue; }
				if (nr == v[0] && nc == 1) { continue; }
				if (nr == v[1] && nc == 1) { continue; }
				operation[nr][nc] += temp;
			}
		}
	}

}

void operationing() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int temp = board[i][j] / 5;
			int minor = temp * check[i][j];
			board[i][j] = board[i][j] - minor + operation[i][j];
		}
	}



}

void max() {
	int max = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] > 0) {
				max += board[i][j];
			}
		}
	}
	cout << max;
	max = 0;

}

void clean_up() {
	for (int i = v[0] - 1; i > 1; i--)
	{
		board[i][1] = board[i - 1][1];
	}
	for (int i = 1; i < C; i++) {
		board[1][i] = board[1][i + 1];
	}

	for (int i = 1; i < v[0]; i++) {
		board[i][C] = board[i + 1][C];
	}

	for (int i = C; i > 2; i--) {
		board[v[0]][i] = board[v[0]][i - 1];
	}
	board[v[0]][2] = 0;


}
void clean_down() {
	for (int i = v[1] + 1; i < R; i++) {
		board[i][1] = board[i + 1][1];
	}
	for (int i = 1; i < C; i++) {
		board[R][i] = board[R][i + 1];
	}
	for (int i = R; i > v[1]; i--) {
		board[i][C] = board[i - 1][C];
	}
	for (int i = C; i > 1; i--) {
		board[v[1]][i] = board[v[1]][i - 1];
	}

	board[v[1]][2] = 0;

}

void init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			operation[i][j] = 0;
			check[i][j] = 4;
		}
	}

}

int main()
{
	cin >> R >> C >> T;
	//V[0],1과 V[1],1에  공기청정기의 좌표가 기록되어 있다.


	setboard();

	for (int x = 0; x < T; x++) {
		init();
		check_board();
		set_operation_board();
		operationing();
		clean_up();
		clean_down();
	}
	max();


}