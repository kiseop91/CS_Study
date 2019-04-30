#include <vector>
using namespace std;

vector<bool> v;

int main()
{
	int m, n;
	cin >> m >> n;

	for (int i = 0; i <= n; i++) {
		v.push_back(true);
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i * 2; j <= n; j = j + i) {
			if (v[j] == 0) { continue; }
			v[j] = 0;
		}
	}
	vector<int> result;
	for (int i = m; i <= n; i++)
	{
		if (v[i] == 0) { continue; }
		result.push_back(i);
	}
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) { printf("%d", result[i]); return 0; }
		printf("%d\n", result[i]);
	}

}
//bool 타입을 최대한 사용하도록 하자 
