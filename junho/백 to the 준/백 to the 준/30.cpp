#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v;
	int zero_count = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') { zero_count += 1; }
		v.push_back(s[i]-'0');
	}
	int a_s = 0;
	for (int i = 0; i < v.size(); i++) {
		a_s += v[i];
	}

	if (zero_count == 0) {
		cout << -1 << endl;
		return 0;
	}
	if (a_s % 3 != 0) {
		cout << -1 << endl;
		return 0;
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	return 0;
}