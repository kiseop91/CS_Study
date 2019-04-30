#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	int gap = 'a' - 'A';
	int idx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') {
			answer.push_back(' ');
			idx = 1;
		}
		else if (idx % 2 == 0) {
			if (s[i] <= 'z' && s[i] >= 'a')
				answer.push_back((char)(s[i] - gap));
			else if (s[i] <= 'Z' && s[i] >= 'A')
				answer.push_back(s[i]);
		}
		else {
			if (s[i] <= 'z' && s[i] >= 'a')
				answer.push_back(s[i]);
			else if (s[i] <= 'Z' && s[i] >= 'A')
				answer.push_back((char)(s[i] + gap));
		}
		idx++;
	}
	return answer;
}