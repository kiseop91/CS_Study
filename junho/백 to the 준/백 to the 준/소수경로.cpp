#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int change(int now, int i,int j) {
	if (i == 1) {
		int a = now % 10;
		a = j - a;
		return now + a;
	}
	else if (i == 2) {
		int a = now % 100;
		a=a / 10;
		a = j- a;
		a = a * 10;
		return now + a;

	}
	else if (i == 3) {
		int a = now % 1000;
		a = a / 100;
		a = j - a;
		a = a * 100;
		return now + a;

	}
	else {
		int a = now / 1000;
		a = j - a;
		a = a * 1000;
		return now + a;

	}
	

}

int main() {
	int a=0;
	cin >> a;
	bool sosu[100001];
	bool visited[100001];
	int dist[100001];
	memset(sosu, false, sizeof(sosu));

	
	for (int z = 0; z < a; z++) {
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		queue<int> q;
		
	
		int n, k;
		cin >> n >> k;
		dist[n] = 0;

		for (int i = 2; i <= sqrt(10001); i++) {      //에스테라노스의 체 소수인것 =false , 소수아닌것 true
			if (sosu[i] == true) { continue; }
			for (int j = i + i; j <= k; j += i) {
				sosu[j] = true;
			}
		}

		q.push(n);		//시작숫자 
		visited[n] = true; //시작지점 방문처리

		while (!q.empty()) {   //bfs
			int now = q.front(); 
			q.pop();
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if (!visited[next] && !sosu[next]) {  //sosu가 false 이면 홀수 , visited false 방문안함
						if (next < 1000) { continue; }
						visited[next] = true;
						q.push(next);
						dist[next] = dist[now] + 1;
					}
				}
			}
		}

		cout << dist[k] << endl;

	}
	
}