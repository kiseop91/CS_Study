#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int n;
struct grade {
	string name;
	int kor;
	int eng;
	int math;
};
grade g[100001];




bool cmp(const grade& a, const grade& b) {
	if (a.kor > b.kor) { return true; }
	else if (a.kor == b.kor) {
		if (a.eng < b.eng) { return true; }
		else if (a.eng == b.eng) {
			if (a.math > b.math) { return true; }
			else if (a.math == b.math) {
				if (a.name < b.name) {//요조건 문제,,,
					return true;
				}
			}
		}

	}
	return false;
}
int main() {

	cin >> n;

	//구조체를 생성하여 입력받음
	for (int i = 0; i < n; i++) {
		cin >> g[i].name >> g[i].kor >> g[i].eng >> g[i].math;
	}

	sort(g, g + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << g[i].name << "\n";
	}
}