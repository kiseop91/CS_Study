#include iostream
#include algorithm
#include vector
using namespace std;
int N, M;
int ans = 0;
vectorint trust[10001];
vectorint visited;
vectorint res;
void dfs(int node);
int main() {

	scanf(%d %d, &N, &M);
	int s, e;
	for (int i = 0; i  M; i++) {
		scanf(%d %d, &s, &e);
		trust[s].push_back(e);
	}
	res = vectorint(N + 1, 0);
	for (int i = 1; i = N; i++) {
		visited = vectorint(N + 1, 0);
		visited[i]++;
		dfs(i);
	}
	for (int i = 1; i = N; i++) {
		if (res[i] == ans) {
			printf(%d , i);
		}
	}
	return 0;
}

void dfs(int node) {

	res[node]++;
	ans = max(ans, res[node]);
	for (int i = 0; i  trust[node].size(); i++) {
		int next_node = trust[node][i];
		if (!visited[next_node]) {
			visited[next_node]++;
			dfs(next_node);
		}
	}
}