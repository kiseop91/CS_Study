#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>	
using namespace std;
/////////
vector<vector<int>> map(25, vector<int>(25, 0));
vector<vector<int>> visited(25, vector<int>(25, 0));
vector<vector<int>> init(25, vector<int>(25, 0));
int res;
int n;
int tmp;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
/////////
void input();
void test(const vector<vector<int>>& map);
void solution();
bool safe(int x, int y);
/////////
struct babyShark
{
	int x, y;
	int size = 2;
	int cnt = 0;

	babyShark(int x, int y)
		:x(x), y(y) {}

	void sizeUp() {
		cnt = 0;
		size++;
	}
};

struct point
{
	int x, y;
	int len;

	const bool operator<(const point& rhs) const {
		if (len == rhs.len)
		{
			if (x == rhs.x)
				return y > rhs.y;
			return x > rhs.x;
		}
		return len > rhs.len;
	}
};

//////
babyShark shark{ 0,0 };
int main()
{
	input();

	solution();

	//test(map);

	cout << res;

	return 0;
}


void solution()
{
	priority_queue<point> q;
	q.push({ shark.x, shark.y, 0 });
	visited[shark.x][shark.y] = 1;

	while (!q.empty())
	{
		point now = q.top();
		q.pop();
		if (map[now.x][now.y] != 0 && shark.size > map[now.x][now.y]) {
			shark.x = now.x;
			shark.y = now.y;
			shark.cnt++;
			map[now.x][now.y] = 0;
			if (shark.cnt == shark.size)
				shark.sizeUp();
			visited = init;
			while (!q.empty()) q.pop();
			res = now.len;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (!safe(nx, ny))
				continue;
			if (map[nx][ny] > shark.size || visited[nx][ny])
				continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny,now.len + 1 });

		}
	}
}

bool safe(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark = { i,j };
				map[i][j] = 0;
			}
		}
	}
}

void test(const vector<vector<int>>& map)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}