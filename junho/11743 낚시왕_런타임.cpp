#include <iostream>

using namespace std;

int board[102][102];
int check[102][102];
bool fish_remain[15004];
int result;

struct fish {

	int r;   //(r,c)는 상어의 위치
	int c;
	int s; //s는 속력
	int d; //d는 이동방향    1=위 2=아래 3오른쪽 4왼쪽
	int z; //z는 크기

};

struct fish fish[15004];

int R, C, M;
void set_board() {
	cin >> R >> C >> M;
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			board[i][j] = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> fish[i].r >> fish[i].c >> fish[i].s >> fish[i].d >> fish[i].z;
		board[fish[i].r][fish[i].c] = i;
		fish_remain[i] = 1;
		check[fish[i].r][fish[i].c] = 1;
	}
}
void fishing(int x) {
	int p = x;
	for (int q = 1; q <= C; q++) {
		if (check[q][p] == 1) {
			result += fish[board[q][p]].z;
			fish_remain[board[q][p]] = 0;
			board[q][p] = 0;
			check[q][p] = 0; return;
		}
	}
	return;
}

void fish_move() {
	for (int i = 1; i <= M; i++) {
		if (!fish_remain[i]) { continue; }

		int speed = fish[i].s;
		int dir = fish[i].d;
		int size = fish[i].z;

		if (dir == 1 or dir == 2) {
			for (int j = 0; j < speed; j++) {
				if (fish[i].d == 1) {
					fish[i].r -= 1;
					if (fish[i].r == 1) {
						fish[i].d = 2;
					}
				}
				else {
					fish[i].r += 1;
					if (fish[i].r == R) { fish[i].d = 1; }
				}
			}
		}
		if (dir == 3 or dir == 4) {
			for (int j = 0; j < speed; j++) {
				if (fish[i].d == 3) {
					fish[i].c += 1;
					if (fish[i].c == C) { fish[i].d = 4; }
				}
				else {
					fish[i].c -= 1;
					if (fish[i].c == 1) { fish[i].d = 3; }
				}
			}
		}
		int nr = fish[i].r;
		int nc = fish[i].c;
		if (check[nr][nc] == 0) { board[nr][nc] = i; check[nr][nc] = 1; }
		else {
			if (size > fish[board[nr][nc]].s) {
				fish_remain[board[nr][nc]] = 0;
			}
			else {
				fish_remain[i] = 0;
			}
		}
	}
}

void board_print() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << board[i][j] << " ";
		}
	}
}

void check_init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			check[i][j] = 0;
		}

	}

}

void board_init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			board[i][j] = 0;
		}
	}
}


int main() {
	set_board(); //테스트케이스는 정상작동이지만 이부분을 주석처리 하지않으면 런타임에러 발생

	for (int x = 1; x <= C; x++) {
		fishing(x);
		check_init();
		board_init();

		fish_move();
		for (int i = 1; i <= M; i++) {
			if (!fish_remain[i]) { continue; }
			board[fish[i].r][fish[i].c] = i;
		}
	}
	cout << result;
}
