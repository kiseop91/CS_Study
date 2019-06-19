#include <iostream>
#include <vector>

using namespace std;

int N;//동전의 종류의 개수
int K;//목표 금액
vector<int> M; //화폐의 가치
int cnt; //동전의 개수


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
