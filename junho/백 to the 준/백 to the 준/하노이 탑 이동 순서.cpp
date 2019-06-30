#include <iostream>

using namespace std;

int cnt = 0;


void move(int x,int y,int n) {//x에서 y로 n개를 옮긴다.

	if (n == 1) { 
		cout << x << " " << y << "\n";
		cnt++;
		return;
	}
	move(x, 6-x-y, n - 1);
	cout << x << " " << y << "\n";
	cnt++;
	move(6 - x - y, y, n - 1);
	
}

int main() {
	int n;
	cin >> n;
	move(1, 3, n);

	cout << cnt;

	//cnt를 먼저 사용하는게 문제의 조건이다.
	//해결방법"바로출력이 아닌 vector에 넣고 벡터사이즈 부터 출력한 후 나머지 벡터내용 출력
}


/*하노이탑 이동순서는 크게 3가지 단계로 볼 수 있따
1번에 있는탑을 3번으로 옮기기 위해서는 3단계가 있다.

1단계: 1부터 n-1까지의 탑 (n위의 모든것) 을 2번으로 옮긴다.
2단계: n을 1에서 3로 옮긴다.
3단계: 2번에 있는 n-1을 3번으로 옮긴다.
*/