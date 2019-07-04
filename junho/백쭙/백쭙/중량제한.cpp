#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int island, bridge;
vector<pair<int, int>> graph[100005];
bool visited[100005];


bool check(int start, int finish, int cost) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == finish) { return true; }

		for (int i = 0; i <graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;
			if (!visited[next] && cost<=nextCost ) {
				visited[next] = true;
				q.push(next);
				}
			}
		}
	
	return  false;

}

int main() {
	cin >> island >> bridge;

	int cmp_1, cmp_2, cmp_3;
	int _max = 0;;
	for (int i = 0; i < bridge; i++) {
		cin >> cmp_1 >> cmp_2 >> cmp_3;
		graph[cmp_1].push_back(make_pair(cmp_2, cmp_3));
		graph[cmp_2].push_back(make_pair(cmp_1, cmp_3));
		if (_max < cmp_3) { _max = cmp_3; }
	}
	int x, y;
	cin >> x >> y;

	int left = 0;
	int right = _max;
	int mid;
	int res = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (check(x, y, mid)) {
			if (res < mid) {
				res = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}


	cout << right<<"\n";


}