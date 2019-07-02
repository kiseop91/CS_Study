#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 200 + 1;

int A, B, C;
bool cache[MAX][MAX][MAX];


vector<int> BFS(void) {
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(0, 0), C));
	vector<int> result;
	
	while (!q.empty()) 
	{
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (cache[a][b][c]) { continue; }
		cache[a][b][c] = true;

		if (a == 0) { result.push_back(c); }

		if (a + b > B) {
			q.push(make_pair(make_pair(a + b - B, B), c));
		}
		else {
			q.push(make_pair(make_pair(0, a + b), c));
		}

		if (a + c > C) {
			q.push(make_pair(a + b - C, b), c)));
		}
	}

}