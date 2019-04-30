#include <vector>
using namespace std;

vector<bool> v;

long long solution(int N) {
	long long answer = 0;
	for (int i = 0; i <= N; i++) {
		v.push_back(true);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i * 2; j <= N; j = j + i) {
			if (v[j] == false) { continue; }
			v[j] = false;
		}
		if (v[i] == false) { continue; }
		answer += i;
	}
	return answer;
}

//bool 타입을 최대한 사용하도록 하자 
