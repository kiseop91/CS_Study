#include <iostream>
#include <vector>

using namespace std;

int N;//������ ������ ����
int K;//��ǥ �ݾ�
vector<int> M; //ȭ���� ��ġ
int cnt; //������ ����


int main() {
	cin >> N >> K;
	int temp = 0;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		M.push_back(temp);
	}
	for (int i = N-1; i >= 0; i--) {
		temp = K / M[i];
		if (temp == 0) { continue; }
		cnt +=temp;
		temp = temp * M[i];
		K -= temp;
	}
	cout << cnt;



}
