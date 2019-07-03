#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

long long island, bridge;
long long arr[10005][10005];


bool check(long long x, long long y, long long m) {
	queue<long long> q;
	q.push(x);
	bool visited[1000000];
	memset(visited, false, sizeof(visited));
	visited[x] = true;
	while (!q.empty()) {
		long long cur = q.front();
		q.pop();
		for (long long i = 1; i <= island; i++) {
			if (visited[i] == true) { continue; }
			if (arr[cur][i] == 0) { continue; }
			if (arr[cur][i] >= m && i==y ) { return true; }
			q.push(i);
			cout << "push[ " << i << "]" << endl;
			visited[i] = true;
		}
	}
	return  false;

}

int main() {
	cin >> island>> bridge;
	
	long long cmp_1,cmp_2,cmp_3;
	long long _max = 0;;
	for (int i = 1; i <= island; i++) {
		cin >> cmp_1>>cmp_2>>cmp_3;
		arr[cmp_1][cmp_2] = cmp_3;
		if (_max < cmp_3){ _max = cmp_3; }
	}
	long long tar_x, tar_y;
	cin >> tar_x>> tar_y;

	long long left = 0;
	long long right = _max;
	long long mid;
	
	while (left <= right) {
		mid = (left + right) / 2;
		cout << mid;
		
		if (check(tar_x, tar_y, mid)) {
			left = mid + 1;
			cout << "true\n";
		}
		else {
			right=mid-1;
			cout << "false\n";
		}
	}





}