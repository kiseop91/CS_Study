#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //����� ��
vector <int> time; //�����ϴµ� �ɸ��� �ð�
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