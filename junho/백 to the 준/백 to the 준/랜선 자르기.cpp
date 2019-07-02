#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long check(long long len, vector<long long> v) {
	long long ans = 0;
	for (long long i = 0; i < v.size(); i++) {
		ans += v[i] / len;
	}
	return ans;
}

int main() {
	long long K, N;
	long long ans = 0;
	cin >> K >> N;

	vector<long long> v(K);
	
	for (long long i = 0; i < K; i++) {
		cin>>v[i];
	}
	long long left = 1;
	long long right = *max_element(v.begin(), v.end());
	long long mid;
	long long res = 0;

	while (left<=right) {
		mid = (left + right) / 2;
		ans = check(mid, v);
		if (ans >= N) {
			res = max(res, mid);

		}
	if (ans >= N) {
		left = mid + 1;
	}
	else {
		right = mid-1;
	}

	}
	cout << res;

}