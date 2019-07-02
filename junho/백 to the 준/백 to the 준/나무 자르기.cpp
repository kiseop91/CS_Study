#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long check(long long mid, vector<long long> v) {
	long long ans = 0;;
	for (long long i = 0; i < v.size(); i++) {
		if (v[i] > mid) {
			ans += v[i] - mid;
		}
	}
	return ans;
}

int main() {
	long long n, m; //n =�������� m=�����ΰ�������
	//�츮�� ���ؾ��ϴ� h=���� ������ �ִ�
	cin >> n >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	long long left = 0;
	long long right = *max_element(v.begin(), v.end());
	long long res = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long ans = check(mid, v);
		
		if (ans >= m) {
			res=max(res, mid);
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}

	}
	cout << res;


}