#include <string>
#include <stack>
#include <stdio.h>
#include <iostream>

using namespace std;

int mul = 1;
int sum = 0;
int main(void) {
	string str;
	cin >> str;
	stack<char> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') {
			mul *= 2;
			s.push(str[i]);
		}

		else if (str[i] == '[') {
			mul *= 3;
			s.push(str[i]);
		}

		if (str[i] == ')' && s.empty()) { cout << 0; return 0; }
		if (str[i] == ']' && s.empty()) { cout << 0; return 0; }
		if (str[i] == ')' && s.top() != '(') { cout << 0; return 0; }
		if (str[i] == ']' && s.top() != '[') { cout << 0; return 0; }

		if (str[i] == ')') {
			if (str[i - 1] == '(') {
				sum += mul; mul /= 2; s.pop();
			}
			else {
				mul /= 2; s.pop();
			}
		}

		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				sum += mul; mul /= 3; s.pop();
			}
			else {
				mul /= 3; s.pop();
			}
		}


	}
	if (s.empty()) { cout << sum;  return 0; }
	else {
		cout << 0; return 0;
	}
}
