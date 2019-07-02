#include <iostream>
#include <queue>
using namespace std;
const int _MAX = 100000 + 1;

bool visited[_MAX];
int dist[_MAX];
int main() {
	int N, K;
	cin >> N >> K;
	//5->17로 가는 최단거리
	queue<int> q;
	q.push(N);
	visited[N] = true;

	while (!q.empty()) {
		int c = q.front();
		q.pop();
			if (c * 2 <= _MAX && visited[c*2]==false) {
				visited[c * 2] = true;
				q.push(c * 2);
				dist[c * 2] = dist[c] + 1;
			}
			if (c + 1 <= _MAX && visited[c+1] == false) {
				visited[c + 1] = true;
				q.push(c + 1);
				dist[c + 1] = dist[c] + 1;
			}
			if (c -1 >= 0 && visited[c-1] == false) {
				visited[c -1] = true;
				q.push(c - 1);
				dist[c -1] = dist[c] + 1;
			}
	}
	cout << dist[K];


}