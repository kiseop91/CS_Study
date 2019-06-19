#include <string>
#include <iostream>

using namespace std;

string str;

int main() {
	for (int i = 0; i < 100; i++) {
		getline(cin, str);
		cout << str << "\n";
	}
	return 0;
}