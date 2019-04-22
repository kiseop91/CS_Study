#include <iostream>
#include <vector>

using namespace std;
int r, c, m;
struct shark {
	int x, y, s, d, z = 0;
	shark(int x = 0, int y = 0, int s = 0, int d = 0, int z = 0)
		:x(x), y(y), s(s), d(d), z(z) {}
};
enum dir { d, up, down, right, left };
vector<vector<shark>> map(101, vector<shark>(101, { 0,0,0,0,0 }));
vector<vector<shark>> copymap(101, vector<shark>(101, { 0,0,0,0,0 }));
vector<vector<shark>> init(101, vector<shark>(101, { 0,0,0,0,0 }));

void input()
{
	//cin >> r >> c >> m;
	scanf("%d %d %d", &r, &c, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, s, d, z;
		//cin >> x >> y >> s >> d >> z;
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		map[x][y] = { x,y,s,d,z };
	}
}
struct Person {
	int x = 1;
	int res = 0;
};
Person person;
void catchShark()
{
	int x = person.x;
	for (int i = 1; i <= r; i++)
	{
		if (map[i][x].z) {
			person.res += map[i][x].z;
			map[i][x] = { 0,0,0,0,0 }; //������� �ʿ��� ����.
			break;
		}
	}
	person.x++;
	//ToDo :  shark remove in map;

}

shark killShark(shark a, shark b) //a�� ���ڸ��� �ִ� ���, b�� ������ ��
{
	if (a.z < b.z) {
		return b;
	}
	else if (a.z >= b.z)
		return a;
	//���� �� ��ũ�� ���� ����.
}

void moveShark()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j].z)//�����ũ�Ⱑ 0�̸� ���°ɷ�ó��.
			{
				shark now = map[i][j];
				//map[i][j] = { 0,0,0,0,0 };
				int dir = now.d;
				if (dir == dir::right)
				{
					//int nx = now.x; //����
					if (c > now.y + now.s) //�ѹ��� �̵�����
					{
						now.y += now.s;
					}
					else if (c == now.y + now.s)//���ΰ��. ���⸸�ٲ��ָ�ȴ�.
					{
						now.y += now.s; now.d = dir::left;
					}
					else//���� �΋H���� ���.
					{
						int ny = 0;
						ny = c - now.y;
						ny = now.s - ny;
						now.d = dir::left;
						int share = ny / (c - 1);
						int spare = ny % (c - 1);
						if (share % 2 == 1)
						{ //���� ������, 1���� ���������� ��������ŭ�̵�.
							now.y = 1 + spare;
							now.d = dir::right;
						}
						else if (share % 2 == 0)
						{ //��������, �������� ��������ŭ�̵�
							now.y = c - spare;
						}
					}
					if (copymap[now.x][now.y].z)
					{
						copymap[now.x][now.y] = killShark(copymap[now.x][now.y], now);
					}
					else
						copymap[now.x][now.y] = { now.x,now.y,now.s,now.d,now.z };

				}
				///////////////////////////////
				if (dir == dir::left)
				{
					//int nx = now.x; //����
					if (now.y - now.s > 1) //�ѹ��� �̵�����
					{
						now.y -= now.s;
					}
					else if (now.y - now.s == 1)//���ΰ��. ���⸸�ٲ��ָ�ȴ�.
					{
						now.y -= now.s; now.d = dir::right;
					}
					else//���� �΋H���� ���.
					{
						int ny = 0; //ny�� ���� �̵��Ÿ�.
						ny = now.y - 1;
						ny = now.s - ny;
						now.d = dir::right;
						int share = ny / (c - 1);
						int spare = ny % (c - 1);
						if (share % 2 == 1)
						{ //���� ���� , r���� �������� ��������ŭ�̵�.
							now.y = c - spare;
							now.d = dir::left;
						}
						else if (share % 2 == 0)
						{ //��������, ���������� ��������ŭ�̵�
							now.y = 1 + spare;
						}
					}
					if (copymap[now.x][now.y].z)
					{
						copymap[now.x][now.y] = killShark(copymap[now.x][now.y], now);
					}
					else
						copymap[now.x][now.y] = { now.x,now.y,now.s,now.d,now.z };
				}
				///////////////////////////
				if (dir == dir::up)
				{
					//int ny = now.y; //����
					if (now.x - now.s > 1) //�ѹ��� �̵�����
					{
						now.x -= now.s;
					}
					else if (now.x - now.s == 1)//���ΰ��. ���⸸�ٲ��ָ�ȴ�.
					{
						now.x -= now.s; now.d = dir::down;
					}
					else//���� �΋H���� ���.
					{
						int nx = 0; //ny�� ���� �̵��Ÿ�.
						nx = now.x - 1;
						nx = now.s - nx;
						now.d = dir::down;
						int share = nx / (r - 1);
						int spare = nx % (r - 1);
						if (share % 2 == 1)
						{ //���� �Ʒ��� , c���� �������� ��������ŭ�̵�.
							now.x = r - spare;
							now.d = dir::up;
						}
						else if (share % 2 == 0)
						{ //��������, �������� ��������ŭ�̵�
							now.x = 1 + spare;
						}
					}
					if (copymap[now.x][now.y].z)
					{
						copymap[now.x][now.y] = killShark(copymap[now.x][now.y], now);
					}
					else
						copymap[now.x][now.y] = { now.x,now.y,now.s,now.d,now.z };
				}
				//////////////////////
				if (dir == dir::down)
				{
					//int nx = now.x; //����
					if (r > now.x + now.s) //�ѹ��� �̵�����
					{
						now.x += now.s;
					}
					else if (r == now.x + now.s)//���ΰ��. ���⸸�ٲ��ָ�ȴ�.
					{
						now.x += now.s; now.d = dir::up;
					}
					else//���� �΋H���� ���.
					{
						int nx = 0;
						nx = r - now.x;
						nx = now.s - nx;
						now.d = dir::up;
						int share = nx / (r - 1);
						int spare = nx % (r - 1);
						if (share % 2 == 1)
						{ //���� ������, 1���� ���������� ��������ŭ�̵�.
							now.x = 1 + spare;
							now.d = dir::down;
						}
						else if (share % 2 == 0)
						{ //��������, �������� ��������ŭ�̵�
							now.x = r - spare;
						}
					}
					if (copymap[now.x][now.y].z)
					{
						copymap[now.x][now.y] = killShark(copymap[now.x][now.y], now);
					}
					else
						copymap[now.x][now.y] = { now.x,now.y,now.s,now.d,now.z };

				}
			}
		}
	}
	//�̵��Ϸ�.
	map = copymap;
	copymap = init;
}

void print()
{
	cout << endl;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << map[i][j].z << " ";
		}
		cout << endl;
	}
}

void solve()
{
	input();
	//	print();
		//cout << endl;
	for (int i = 1; i <= c; i++)
	{
		if (m == 0)
			break;
		catchShark();
		moveShark();
		//	print();
			//cout << endl;
	}
	cout << person.res << endl;
}
int main()
{
	solve();

}
/*
4 6 1
3 6 2 1 2

4 6 1
4 1 3 3 8

4 4 1
3 2 9 1 1

4 4 1
3 2 8 1 1

4 4 1
3 2 7 1 1

4 4 1
3 2 6 1 1

4 4 1
3 2 5 1 1

4 4 1
3 2 4 1 1

4 4 1
3 2 3 1 1

4 4 1
3 2 2 1 1

4 4 1
3 2 1 1 1

4 4 1
3 2 0 4 1
*/