#include <iostream>
#include <stdio.h>
#include <array>
#include <queue>
#include <string.h>

using namespace std;
int check[1001][10001];
int visited[1001];
int n, m, start;


void dfs(int cmp)
{
	printf("%d ", cmp);
	visited[cmp] = 1;
	for (int i = 1; i <= n; i++) {

		if (check[cmp][i] == 0)continue;
		if (visited[i] == 1)continue;

		dfs(i);
	}
	return;
}

void bfs(int cmp)
{
	queue<int> q;
	q.push(cmp);
	while (!q.empty())
	{
		int nr = q.front();
		q.pop();
		visited[nr] = 1;
		cout << nr << " ";
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 1)continue;
			if (check[nr][i] == 0)continue;
			visited[i] = 1;
			q.push(i);
		}
	}
	return;
}

int main() {
	cin >> n >> m >> start;

	int a, b;


	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		check[a][b] = 1;
		check[b][a] = 1;

	}

	dfs(start);

	memset(visited, 0, sizeof(visited));

	cout << "\n";

	bfs(start);
	return 0;
}