#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
vector<char> v;
void backTracking(int pos,int ja,int mo,int now_len,string s) {
	if (now_len == L) {
		if (ja >= 2 && mo >= 1) {
			cout << s << "\n";
		}
		return;
	}

	
	for (int i = pos; i < C; i++) {
		if (v[i] == 'a' or v[i] == 'e' or v[i] == 'i' or v[i] == 'o' or v[i] == 'u') {
			backTracking(i + 1, ja, mo + 1, now_len + 1, s + v[i]);
		}
		else {
			backTracking(i + 1, ja + 1, mo, now_len + 1, s + v[i]);
		}
	}
	
		
}



int main() {
	cin >> L >> C;
	v.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	string s = "";
	backTracking(0, 0, 0, 0, s);

	return 0;


}