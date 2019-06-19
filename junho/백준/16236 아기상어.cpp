#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct fish {
	int r;
	int c;
	int size; //���������
	int eat; //���� ����� ��
	int time; //�̵��Ÿ�
};
int n;

fish ex;
queue<fish> q;
int board[21][21];
int visit[21][21];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
vector<fish> v;

bool cmp(fish a, fish b);

int main() 
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &board[i][j]);

			if (board[i][j] == 9) {
				board[i][j] = 0;  //��Ŷ��� ����
				ex = { i,j,2,0,0 };
			}

		}

	}

	int ans = 0;
	
	while (1) {

		v.clear();
		memset(visit, 0, sizeof(visit));
		visit[ex.r][ex.c] = 1;
		q.push(ex);


		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int size = q.front().size;
			int eat = q.front().eat;
			int time = q.front().time;
			q.pop();


			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				/*
				if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

					// �� ����� ��ȿ�ϰ� �湮���� ���� ����

					if (!visit[nr][nc]) {

						// ����� ���� ����̰ų� ���� ���

						if (board[nr][nc] == 0 || board[nr][nc] == size) {

							// �湮 ó��

							visit[nr][nc] = 1;

							// �ð��� �߰��ϰ� ��� ���� �� ã��

							q.push({ nr, nc, size, eat, time + 1 });

						}

						// ���� ���� �� �ִٸ�

						else if (board[nr][nc] < size) {

							// �湮 ó��

							visit[nr][nc] = 1;

							// ��� ���� ���� �ð��� ǥ���ϰ� ���Ϳ� ���� ����

							v.push_back({ nr, nc, size, eat + 1, time + 1 });

						}

					}

				}

			}

		}*/

				if (visit[nr][nc] == 1) { continue; }
				if (nr < 0 or nr >= n or nc < 0 or nc >= n) { continue; }
				visit[nr][nc] = 1;
				if (board[nr][nc] == 0 or board[nr][nc] == size) {
					q.push({ nr,nc,size,eat,time + 1 });
				}
				else if (board[nr][nc] > 0 && board[nr][nc] < size)
				{
					v.push_back({ nr,nc,size,eat + 1,time + 1 });
				}
			}
		}
	
	//	printf("v.size==%d\n", v.size());
		if (v.size() == 0) {
		//	printf("break\n");
			break;

		}


		sort(v.begin(), v.end(), cmp);
		if (v[0].size == v[0].eat) {
			v[0].size++;
			v[0].eat = 0;
		}
		board[v[0].r][v[0].c] = 0;
		ans += v[0].time;
		ex = { v[0].r,v[0].c,v[0].size,v[0].eat,0 };

	}
	printf("%d", ans);
	return 0;
}



/*void input_board(int n, fish ex)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &board[i][j]);
			
			if (board[i][j] == 9) {
	
				ex = { i,j,2,0,0 };
			}

		}

	}
	return;

}*/

bool cmp(fish a, fish b) 
{
	if (a.time <= b.time) { //a�� �ð��� b�� �ð����� ª����=�������� return false;
		if (a.time == b.time) {
			if (a.r <= b.r) {
				if (a.r == b.r) {
					if (a.c <= b.c)
					{
						return true;//a�� y��ǥ�� b�� y��ǥ���� �����Ƿ� true;
						//�̰����� <=�� �ƴ϶� <�� ������ x,y��ǥ�� ������ ���� �������̶�� ���� �Ǳ⶧���� 
					}
					return false; //a�� y��ǥ�� b�� y��ǥ���� ũ�Ƿ� fasle;
				}			
				return true; //a.x�� ��ǥ�� b.x�� ��ǥ���� �۴� true
			}
			return false; //a.x��ǥ�� b.x��ǥ���� ũ��->b���������ִ� fasle
		}
		return true;//a.time<b.time a���� �����Ƿ� true
	}
	return false; //a�� �ð��� b�� �ð����� �����ɸ�->a�� b���� �ִ�
	//b�� �� �����ٴ� �ǹ��̹Ƿ� return false;

}

/*
void init() 
{
	v.clear();
	memset(visit, 0, sizeof(visit));
	visit[ex.r][ex.c] = 1;
	q.push(ex);
}*/

