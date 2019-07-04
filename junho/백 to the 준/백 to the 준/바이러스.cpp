#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool computer[101][101];
bool visited[101];
int main() {
	int com,line;

	cin >> com >> line;

	int start, next;

	for (int i = 0; i < line; i++) {
		cin >> start >> next;
		computer[start][next] = true;
		computer[next][start] = true;
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int cnt = 0;
	while (!q.empty()) {
		int ans = q.front();
		q.pop();
		cnt++;
		for (int i = 1; i <= com; i++) {
			if (visited[i] == true) { continue;}
			if (computer[ans][i] == true) { q.push(i); visited[i] = true; }
		}
		


	}
	cout << cnt-1;

}