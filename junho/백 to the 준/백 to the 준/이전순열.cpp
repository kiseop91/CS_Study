#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v;

bool prev_permutation() {
	int idx = N - 1;
	while (idx > 0 && v[idx - 1] <= v[idx])
		idx--;

	if (idx == 0) {
		return false;
	}

	int idx2 = N - 1;
	while (v[idx - 1] <= v[idx2])
		idx2--;

	swap(v[idx - 1], v[idx2]);
	idx2 = N - 1;
	while (idx < idx2)
	{
		swap(v[idx], v[idx2]);
		idx++;
		idx2--;
	}
	return true;

}


int main() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (prev_permutation()) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}
	}
	else {
		cout << -1 << " ";
	}

}