#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {

	string alpa = "abcdefghijklmnopqrstuvwxyz";
	string Alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string answer = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') {
			answer.push_back(' ');
			continue;
		}
		if (s[i] <= 'Z')//대문자
		{
			int idx = (s[i] - 'A' + n) % 26;
			answer.push_back(Alpa[idx]);
		}
		else//소문자
		{
			int idx = (s[i] - 'a' + n) % 26;
			answer.push_back(alpa[idx]);
		}
	}
	return answer;
}