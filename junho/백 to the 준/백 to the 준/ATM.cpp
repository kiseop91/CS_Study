#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //사람의 수
vector <int> time; //인출하는데 걸리는 시간
int ans;

int main() {
	cin >> N;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		time.push_back(temp);
	}

	sort(time.begin(), time.end());
	
	int cmp=0;
	for (int i = 0; i < N; i++) {
		cmp += time[i];
		ans =ans + cmp;
	}
	cout << ans;



	


}