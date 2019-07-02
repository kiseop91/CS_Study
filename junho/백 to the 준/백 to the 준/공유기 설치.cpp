#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long check(long long mid, vector<long long >v) {

	long long a = v[0];
	long long cnt = 0;
	for (int i = 1; i < v.size(); i++) {
		if ( v[i]-a >= mid) {
			cnt++;
			a = v[i];
		}			
	}
	return cnt+1;
}

int main() {
	long long n, m;
	cin >> n >> m;
	
	vector<long long> v(n);

	for(long long i=0;i<n;i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());


	long long left = 1;
	long long right = *max_element(v.begin(), v.end());
	long long res = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		//최소 인접공유기를 mid =현재 초기값 5로 했을때 설치가 가능하냐? yes 안된다 no 
		long long cnt= check(mid, v);
		if (cnt>=m) {
			res = max(res, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}


	}

	cout << res;



}