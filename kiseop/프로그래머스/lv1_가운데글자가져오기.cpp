#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
	string answer = "";
	int len = s.length();
	if (len % 2 == 0)
	{
		answer.push_back(s[len / 2 - 1]);
		answer.push_back(s[len / 2]);
	}
	else
	{
		answer.push_back(s[len / 2]);
	}

	return answer;
}


int main()
{
	cout << solution("abcd") << endl;

	cout << solution("abc") << endl;
}