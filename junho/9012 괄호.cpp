#include<stack>
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int T;
string str;
bool check() {

	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (s.empty()) {
			if (c == '(') {
				s.push(c);
				continue;
			}
			else {
				return false;
			}
		}

		if (c == '(') { s.push(c); }
		else {
			s.pop();
		}
	}
	if (!s.empty()) { return false; }
	else {
		return true;
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (check() == true) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << "\n";

	}
}