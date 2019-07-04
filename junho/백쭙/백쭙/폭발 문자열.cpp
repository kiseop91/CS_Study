#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

const int MAX = 1000005;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string bomb;
	string str;
	cin >> str >> bomb;

	deque<char> s;


	for (int i = 0; i < str.size(); i++) {
		s.push_back(str[i]);
		if (s.size() >= bomb.size()) {
			bool flag = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (s[s.size() - bomb.size() + j] != bomb[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for(int i=0;i<bomb.size();i++){
					s.pop_back();
				}
			}
		}
	}
	if(s.size()>0){
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}
	}
	else {
		cout << "FRULA";
	}


}