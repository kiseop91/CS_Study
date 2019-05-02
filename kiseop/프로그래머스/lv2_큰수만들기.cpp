#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int nMax = 0;
	int nCount = 0;
	int j;
	int res_len = number.length() - k;
	vector<int> v;
	for (int i = res_len; i > 0; i--)
	{
		nMax = 0;
		nCount = 0;
		for (j = 0; j < number.length() - i + 1; j++)
		{
			if (nMax < number[j])
			{
				nMax = number[j];
				nCount = j;
			}
		}
		number.replace(0, nCount + 1, " ");

		v.push_back(nMax);
	}

	///답에 넣기.
	for (int i = 0; i < v.size(); i++)
		answer += v[i];
	return answer;
}


////더 좋은 풀이여서 퍼왔음. 
string solution2(string number, int k) {
	string answer = "";
	answer = number.substr(k);
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}
			else {
				break;
			}
		} while (1);
	}
	return answer;
}


int main()
{
	cout << solution("1924", 2);
}