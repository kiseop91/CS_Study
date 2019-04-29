#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> a, vector<vector<int>> c) {
	vector<int> answer;
	vector<int> v;
	
	for (int i = 0;i< c.size(); i++) {
		for (int j = c[i][0] - 1; j < c[i][1]; j++) {
			v.push_back(a[j]);
		}
		sort(v.begin(), v.end());
		answer.push_back(v[c[i][2]-1]);
		v.clear();
	}

	return answer;
}

int main() {
	vector<int> a = { 1,5,2,6,3,7,4 };
	vector<vector<int>> s = { {2, 5, 3}, {4, 4, 1},{1, 7, 3} };
	solution(a, s);

}