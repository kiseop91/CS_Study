#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	while(1){
	int N;
	cin >> N;
	if (N == 0) { return 0; }
	vector<int>v;
	int cmp;
	for (int i = 0; i < N; i++) {
		cin >> cmp;
		v.push_back(cmp);
	}
	vector<int> a;
	for (int i = 0; i < 6; i++) {
		a.push_back(0);
	}
	for (int i = 0; i < N - 6; i++) {
		a.push_back(1);
	}
	sort(a.begin(), a.end());
	do{
		for (int i = 0; i < N; i++) {
			if (a[i] == 0) {
				cout << v[i] << " ";
			}
		}
		cout << "\n";
	} while (next_permutation(a.begin(), a.end()));
	cout << "\n";
	}

}

