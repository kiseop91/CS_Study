#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int dx[]{ 1,0,-1,0 };
int dy[]{ 0,1,0,-1 };
vector<vector<int>> map(52, vector<int>(52, 0));
vector<vector<int>> copymap(52, vector<int>(52, 0));
vector<vector<int>> init(52, vector<int>(52, 0));
int r, c, t;
struct Aircon {
	int x, y;
	bool chk = false;
};
Aircon topAir = { 0,0 };
Aircon bottomAir = { 0,0 };
bool chk(int x, int y);
void input();
void dustDifuse();
void circulate();
void answer(const vector<vector<int>>& map);

int main()
{
	input();
	for (int i = 0; i < t; i++)
	{
		dustDifuse();
		circulate();
	}
	answer(map);

}

///////////////////////////////////////
bool chk(int x, int y)
{
	return (x >= 1 && x <= r && y >= 1 && y <= c);
}

void circulate()
{
	vector<vector<int >> temp(52, vector<int>(52, 0));
	temp = map; //temp에서 읽어서 copymap에 저장하기.
	//print(temp);
	//cout << endl;
	int x = topAir.x;
	int y = topAir.y;
	for (int i = 2; i <= c; i++)
	{
		map[x][i] = temp[x][i - 1];
		if (map[x][i] == -1)
			map[x][i] = 0;
	}
	for (int i = x - 1; i >= 1; i--)
		map[i][c] = temp[i + 1][c];

	for (int i = c - 1; i >= 1; i--)
		map[1][i] = temp[1][i + 1];

	for (int i = 2; i <= x; i++)
	{
		if (map[i][1] == -1)
			continue;
		else
			map[i][1] = temp[i - 1][1];
	}
	////////////
	x = bottomAir.x;
	y = bottomAir.y;
	for (int i = 2; i <= c; i++)
	{
		map[x][i] = temp[x][i - 1];
		if (map[x][i] == -1)
			map[x][i] = 0;
	}
	for (int i = x + 1; i <= r; i++)
		map[i][c] = temp[i - 1][c];

	for (int i = c - 1; i >= 1; i--)
		map[r][i] = temp[r][i + 1];

	for (int i = r - 1; i >= x; i--)
	{
		if (map[i][1] == -1)
			continue;
		else
			map[i][1] = temp[i + 1][1];
	}
}

void answer(const vector<vector<int>>& map)
{
	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] == -1)
				continue;
			else
			{
				ans += map[i][j];
			}
		}
	}
	cout << ans;
}

void dustDifuse()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (chk(nx, ny) && map[nx][ny] != -1) {
					copymap[nx][ny] += map[i][j] / 5; //확산된 먼지계산.
					cnt++;
				}
			}
			copymap[i][j] += map[i][j] - (map[i][j] / 5 * cnt);  //현재위치 먼지계산.
		}
	}
	map = copymap; //확산완료후 현재맵에 적용시키기.
	copymap = init;// 초기화.
}

void input()
{
	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (topAir.chk)
					bottomAir = { i,j };
				else {
					topAir = { i,j };
					topAir.chk = true;
				}
			}
		}
	}
	//copymap = map;
}