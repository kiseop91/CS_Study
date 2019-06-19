#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //회의의 수

struct Meeting {
	int begin;
	int end;
};

bool cmp(Meeting u, Meeting v) {
	if (u.end == v.end) {
		return u.begin < v.begin;
	}
	else {
		return u.end < v.end;
	}
}

int main() {
	cin >> N;

	vector<Meeting> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i].begin >> a[i].end;
	}

	sort(a.begin(), a.end(), cmp);

	int now = 0;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (now <= a[i].begin) {
			now = a[i].end;
			ans += 1;
		}
	}
	cout << ans;
}