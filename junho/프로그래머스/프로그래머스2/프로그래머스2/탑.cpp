#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> h) {
	vector<int> a(h.size());


	for (int i =0; i < h.size(); i++) {
		for (int j = i-1; j >= 0; j--) { //>로해서 오류 >= 오류 수정 후 정상작동
			if (h[i] < h[j]) { a[i] = j+1; break; }
		}	
	}
	return a;
}


int main() {
	//[6,9,5,7,4]	[0,0,2,2,4]
	vector<int> h = { 1,5,3,6,7,6,5 };

	solution(h);

}