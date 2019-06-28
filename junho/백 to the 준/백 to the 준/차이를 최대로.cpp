#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N;


int main() {
	cin >> N;
	vector<int>v(N);


	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int max_1 = 0;
	int cmp=0;
	do {
		for (int i = 1; i < N; i++) {
			cmp += abs(v[i] - v[i - 1]);
		}
		max_1=max(cmp, max_1);
		cmp = 0;
	} while (next_permutation(v.begin(), v.end()));

	cout << max_1;
}
