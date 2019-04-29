#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	int str = s.size() - 1;
	if (str % 2 == 0) {
		answer = s[str / 2];
	}
	else {
		answer = s[str / 2];
		 char a=s[str / 2 + 1];
		answer.append(1,a);

	}
	cout << answer;
	return answer;
}

int main() {
	string str;
	cin >> str;
	solution(str);

}