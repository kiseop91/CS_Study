#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
	cin >> s;
	string temp = "";
	int result = 0;
	bool minus = false;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' or s[i] == '-' or s[i] == '\0') {
			if (minus) {
				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}
			temp = "";
			if (s[i] == '-') {
				minus = true;
			}
		}
		else {
			temp += s[i];
		}

	}
	cout << result;
}