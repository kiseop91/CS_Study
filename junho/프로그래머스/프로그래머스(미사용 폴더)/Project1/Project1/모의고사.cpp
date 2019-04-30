#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int arr_1[5] = { 1,2,3,4,5 }; //5°³
	int arr_2[8] = { 2,1,2,3,2,4,2,5 }; //8°³
	int arr_3[10] = { 3,3,1,1,2,2,4,4,5,5 };//10°³         
	vector<int> result;
	for (int i = 0; i < 3; i++) {
		result.push_back(0);
	}
	for (int i = 0; i < answers.size(); i++) {
		int a_1 = i % 5;
		int a_2 = i % 8;
		int a_3 = i % 10;
		cout << a_1 << a_2 << a_3<<endl;
		if (answers[i] == arr_1[a_1]) { result[0] += 1; }
		if (answers[i] == arr_2[a_2]) { result[1] += 1; }
		if (answers[i] == arr_3[a_3]) { result[2] += 1; }
	}
	int max_result = max(result[2],max( result[1],result[0]));
	for (int i = 0; i < 3; i++) {
		if (result[i] == max_result) { answer.push_back(i + 1); }
	}
	
	return answer;
}
int main() {
	vector<int> a;
	for(int i=1;i<6;i++){
		a.push_back(i);}
	solution(a);
}