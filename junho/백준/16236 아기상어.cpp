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
	int size; //현재사이즈
	int eat; //먹은 물고기 수
	int time; //이동거리
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
				board[i][j] = 0;  //요거땜에 망함
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

					// 맵 사이즈가 유효하고 방문하지 않은 지역

					if (!visit[nr][nc]) {

						// 사이즈가 같은 상어이거나 길인 경우

						if (board[nr][nc] == 0 || board[nr][nc] == size) {

							// 방문 처리

							visit[nr][nc] = 1;

							// 시간만 추가하고 계속 작은 상어를 찾음

							q.push({ nr, nc, size, eat, time + 1 });

						}

						// 만약 작은 상어가 있다면

						else if (board[nr][nc] < size) {

							// 방문 처리

							visit[nr][nc] = 1;

							// 잡아 먹은 상어와 시간을 표시하고 벡터에 따로 저장

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
	if (a.time <= b.time) { //a의 시간이 b의 시간보다 짧으면=더가까우면 return false;
		if (a.time == b.time) {
			if (a.r <= b.r) {
				if (a.r == b.r) {
					if (a.c <= b.c)
					{
						return true;//a의 y좌표가 b의 y좌표보다 작으므로 true;
						//이곳에서 <=가 아니라 <인 이유는 x,y좌표가 같으면 둘이 같은점이라는 뜻이 되기때문에 
					}
					return false; //a의 y좌표가 b의 y좌표보다 크므로 fasle;
				}			
				return true; //a.x의 좌표가 b.x의 좌표보다 작다 true
			}
			return false; //a.x좌표가 b.x좌표보다 크다->b가더위에있다 fasle
		}
		return true;//a.time<b.time a가더 가까우므로 true
	}
	return false; //a의 시간이 b의 시간보다 오래걸림->a가 b보다 멀다
	//b가 더 가깝다는 의미이므로 return false;

}

/*
void init() 
{
	v.clear();
	memset(visit, 0, sizeof(visit));
	visit[ex.r][ex.c] = 1;
	q.push(ex);
}*/

